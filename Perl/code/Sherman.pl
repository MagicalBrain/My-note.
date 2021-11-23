#!/usr/bin/perl
use warnings FATAL => 'all';
use strict;
use Cwd;
$|++;
use Getopt::Long;

## This program is Copyright (C) 2011-20, Felix Krueger (felix.krueger@babraham.ac.uk)

## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.

## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.

## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>.

my $sherman_version = '0.1.8_dev';
my $parent_dir = getcwd;
my $total_genome_length = 0; ## we need this later to generate random sequences

my %chromosomes;
my %seqs;             # single-end reads or read 1 of paired-end reads
my %seqs_pairs;       # read 2 of paired-end reads

my %counting =(
	       non_directional => 0,
	       uniform_converted => 0,
	       uniform_total => 0,
	       CH_converted => 0,
	       CH_total => 0,
	       CG_converted => 0,
	       CG_total => 0,
	       small => 0,
	       SNPs_introduced => 0,
	      );

my @DNA_bases = ('A','T','C','G');
my @gaussian; # will hold random fragment lengths

my ($sequence_length,$conversion_rate,$number_of_sequences,$error_rate,$number_of_SNPs,$quality,$fixed_length_adapter,$variable_length_adapter,$adapter_dimer,$random,$colorspace,$genome_folder,$non_directional,$CG_conversion_rate,$CH_conversion_rate,$paired_end,$minfrag,$maxfrag,$output_dir) = process_command_line();

print_onscreen_summary();
run_sequence_generation();

sub print_onscreen_summary{
  warn "\nSelected general parameters:\n";
  warn "-"x100,"\n";
  if ($paired_end){
    warn "Paired-end reads selected. Fragment length will be $minfrag-$maxfrag bp\n";
  }
  else{
    warn "Single-end read output format selected\n";
  }
  warn "sequence length:\t$sequence_length bp\n";

  ### making the sequences 1bp longer than it needs to be so we can extract the sequence context again
  ++$sequence_length;

  warn "number of sequences being generated:\t$number_of_sequences\n";
  if ($non_directional){
    warn "Non-directional sequences will be generated, i.e. sequences can originate from any of the four possible bisulfite PCR strands\n";
  }
  if ($colorspace){
    warn "Sequences will be written out as both base space and color space FastQ files\n";
  }
  warn "\n";

  warn "Possible sources of contamination:\n";
  warn "-"x100,"\n";
  warn "overall error rate:\t$error_rate%\n";

  if (defined $conversion_rate){
    if ($conversion_rate == 0){
      warn "\nPlease note that the bisulfite conversion rate was selected as:\t$conversion_rate %\n";
      warn "This means that reads will not be converted at all and thus serve as simulated genomic FastQ sequences\n\n";
    }
    else{
      warn "bisulfite conversion rate:\t$conversion_rate%\n";
    }
  }
  if (defined $CG_conversion_rate and defined $CH_conversion_rate){
    warn "bisulfite conversion rate in CG-context:\t$CG_conversion_rate%\n";
    warn "bisulfite conversion rate in CH-context:\t$CH_conversion_rate%\n";
  }

  if ($number_of_SNPs > 0){
    warn "SNPs to be introduced:\t$number_of_SNPs\n";
  }
  if ($number_of_SNPs > 0 or $error_rate == 0){
    warn "default Phred quality value:\t$quality\n";
  }

  if ($fixed_length_adapter){
    warn "Introducing a fixed length adpater contamination into all sequences:\t $fixed_length_adapter bp\n";
  }
  if ($variable_length_adapter){
    warn "Introducing a variable length of adapter sequence into a proportion of all sequences\n";
    warn "assuming a normal distribution of fragment sizes with a mean fragment length (mu) of $variable_length_adapter (user-specified) and a variance (sigma) of 60 (fixed)\n";
  }
  if ($adapter_dimer){
    warn "Introducing $adapter_dimer% of adapter dimers into the simulated dataset\n";
  }
  warn "\n\n";
  sleep (5);
}

sub run_sequence_generation{

  unless ($random){
    read_genome_into_memory();
  }

  ### Starting simulation
  my $count = 0;

  my $plus_strand_total = 0;
  my $minus_strand_total = 0;

  my $fragment_length = $maxfrag-$minfrag;

  ### GENERATE QUALITY STRING (this quality will be used for all sequences)
  # quality values are of the specified sequence length (and not 1 bp longer)
  my $phred33_quality =  generate_quality_values ();
 
  ### OPENING OUTPUT FILEHANDLES
  if ($paired_end){
    open (FASTQ_R1,'>',"${output_dir}simulated_1.fastq") or die $!;
    open (FASTQ_R2,'>',"${output_dir}simulated_2.fastq") or die $!;
  }
  else{
    open (FASTQ,'>',"${output_dir}simulated.fastq") or die $!;
  }

  if ($colorspace){
    if ($paired_end){
      open (READS_R1,'>',"${output_dir}simulated_1.csfasta") or die $!;
      open (QUALS_R1,'>',"${output_dir}simulated_1_QV.qual") or die $!;
      open (READS_R2,'>',"${output_dir}simulated_2.csfasta") or die $!;
      open (QUALS_R2,'>',"${output_dir}simulated_2_QV.qual") or die $!;
    }
    else{
      open (READS,'>',"${output_dir}simulated.csfasta") or die $!;
      open (QUALS,'>',"${output_dir}simulated_QV.qual") or die $!;
    }
  }

  ### Taken from the FastQC contaminants list:
  ### Illumina Paired End PCR Primer 2; sequence: CAAGCAGAAGACGGCATACGAGATCGGTCTCGGCATTCCTGCTGAACCGCTCTTCCGATCT
  my $adapter_sequence = 'CAAGCAGAAGACGGCATACGAGATCGGTCTCGGCATTCCTGCTGAACCGCTCTTCCGATCT';
  until (length $adapter_sequence > $sequence_length){
    $adapter_sequence .= $adapter_sequence;
  }
  ### as one would be reading into the adapter from the opposite side we need to reverse complement the sequence
  $adapter_sequence = reverse_complement($adapter_sequence);

  if ($variable_length_adapter){
    create_normal_random_numbers();
  }

  until ($count == $number_of_sequences){

    if ($count%250000 == 0){
      warn "$count sequences generated so far\n" unless ($count == 0);
    }

    my $seq_1;
    my $seq_2; # for paired-end reads
    my $genomic_coords;

    ### SEQUENCE GENERATION: RANDOM
    if ($random){
		$seq_1 = generate_random_sequences();
		if ($paired_end){
			$seq_2 = generate_random_sequences();
		}

		### INTRODUCING SNPS
		### It doesn't make sense to introduce SNPs into random sequences, so skipping this part

		### NON-DIRECTIONAL LIBRARIES
		### It doesn't make sense to introduce non-directionality into random sequences, so skipping this part

		### BISULFITE CONVERSION
		if (defined $CG_conversion_rate and defined $CH_conversion_rate){
	$seq_1 = bisulfite_transform_sequences_context_specifically($seq_1);
	if ($paired_end){	
	  $seq_2 = bisulfite_transform_sequences_context_specifically($seq_2);
	}
      }
      else{
	$seq_1 = bisulfite_transform_sequences_uniformly($seq_1) unless ($conversion_rate == 0);
	if ($paired_end){
	  $seq_2 = bisulfite_transform_sequences_uniformly($seq_2) unless ($conversion_rate == 0);
	}
	
	if ($conversion_rate == 0){
	  $seq_1 = substr ($seq_1,0,length ($seq_1) - 1 ); ### need to shorten the sequence by 1 bp again which is otherwise done in the conversion section
	  if ($paired_end){
	    $seq_2 = substr ($seq_2,0,length ($seq_2) - 1 ); ### need to shorten the sequence by 1 bp again which is otherwise done in the conversion section
	  }
	}
      }
    }
    else{ # SEQUENCE GENRATION: GENOMIC SEQUENCES (default)

		my $strand;
		### we need to take slightly different routes for single-end and paired-end sequences
		### PAIRED-END
		if ($paired_end){
		    
		($seq_1,$seq_2,$strand,$genomic_coords) = generate_genomic_sequences_paired_end($conversion_rate);
		if ($strand eq 'plus'){
			$plus_strand_total++;
		}
		else{
			$minus_strand_total++;
		}
		# warn "$genomic_coords\n"; sleep(1);
		### INTRODUCING SNPS
		### we need to introduce SNPs before bisulfite conversion takes place
		if ($number_of_SNPs > 0){
			$seq_1 = introduce_SNPs($seq_1);
			$seq_2 = introduce_SNPs($seq_2);
		}
		
		### BISULFITE CONVERSION
		if (defined $CG_conversion_rate and defined $CH_conversion_rate){
			$seq_1 = bisulfite_transform_sequences_context_specifically($seq_1);
			$seq_2 = bisulfite_transform_sequences_context_specifically($seq_2);
		}
		else{
		if  ($conversion_rate == 0){
			$seq_1 = substr($seq_1,0,length($seq_1)-1); ### need to shorten the sequence by 1 bp again which is otherwise done in the conversion section
			$seq_2 = substr($seq_2,0,length($seq_2)-1); ### need to shorten the sequence by 1 bp again which is otherwise done in the conversion section
		}
		else{
			$seq_1 = bisulfite_transform_sequences_uniformly($seq_1);
			$seq_2 = bisulfite_transform_sequences_uniformly($seq_2);
		}
	}
	### NON-DIRECTIONAL LIBRARIES
	if ($non_directional){
	  my $complemented = make_non_directional_sequences();
	
	  ### We are swapping read 1 and read 2 if we want to get non-directioal reads
	  if ($complemented == 1){
	    $seq_2 = reverse_complement($seq_2);# reverse complementing the paired-end side
	    my $temp = $seq_1;
	    $seq_1 = $seq_2;
	    $seq_2 = $temp;
	  }
	  else{
	    $seq_2 = reverse_complement($seq_2); # reverse complementing the paired-end side
	  }
	}	
	else{
	  $seq_2 = reverse_complement($seq_2); # reverse complementing the paired-end side
	}
      }

      ### SINGLE-END
      else{
	($seq_1,$strand,$genomic_coords) = generate_genomic_sequences ();

	if ($strand eq 'plus'){
	  $plus_strand_total++;
	}
	else{
	  $minus_strand_total++;
	}

	### INTRODUCING SNPS
	### we need to introduce SNPs before bisulfite conversion takes place
	if ($number_of_SNPs > 0){
	  $seq_1 = introduce_SNPs($seq_1);
	}
	### BISULFITE CONVERSION
	if (defined $CG_conversion_rate and defined $CH_conversion_rate){
	  $seq_1 = bisulfite_transform_sequences_context_specifically ($seq_1);
	}
	else{
	  if  ($conversion_rate == 0){
	    $seq_1 = substr($seq_1,0,length($seq_1)-1); ### need to shorten the sequence by 1 bp again which is otherwise done in the conversion section
	  }
	  else{
	    $seq_1 = bisulfite_transform_sequences_uniformly($seq_1);
	  }
	}
	### NON-DIRECTIONAL LIBRARIES
	if ($non_directional){
	  $seq_1 = make_non_directional_sequences($seq_1);
	}
      }
    }

    ++$count;

    ### FIXED-LENGTH ADAPTER
    if ($fixed_length_adapter){
      $seq_1 = introduce_fixed_length_adapter_contamination($seq_1,$adapter_sequence);
      if ($paired_end){
	($seq_2)= introduce_fixed_length_adapter_contamination($seq_2,$adapter_sequence);
      }
    }
    ### VARIABLE LENGTH ADAPTER
    elsif ($variable_length_adapter){
      if ($paired_end){
	($seq_1,$seq_2) = introduce_variable_length_adapter_contamination ($seq_1,$seq_2,$adapter_sequence);
      }
      else{
	($seq_1) = introduce_variable_length_adapter_contamination ($seq_1,undef,$adapter_sequence);
      }
    }

    ### COLORSPACE
    my $seq_1_cs;
    my $seq_2_cs;

    if ($colorspace){
      $seq_1_cs = convert_basespace_to_colorspace($seq_1);
      if ($paired_end){
	$seq_2_cs = convert_basespace_to_colorspace($seq_2);
      }
    }

    ### INTRODUCING BASECALL ERRORS
    ### we won't introduce any additional errors if a specific number of SNPs has been specified or the error rate was set to 0%
    unless ( $error_rate == 0 or $number_of_SNPs > 0){

      ### introducing errors into colorspace data is slightly different to basespace data
      if ($colorspace){
	$seq_1_cs = introduce_sequencing_errors_colorspace($seq_1_cs,$phred33_quality);
	if ($paired_end){
	  $seq_2_cs = introduce_sequencing_errors_colorspace($seq_2_cs,$phred33_quality)
	}
      }

      ### base space errors (default)
      $seq_1 = introduce_sequencing_errors($seq_1,$phred33_quality);
      if ($paired_end){
	$seq_2 = introduce_sequencing_errors($seq_2,$phred33_quality)
      }
    }

    ### Also shortening the quality scores again
    # $phred33_quality = substr($phred33_quality,0,length($phred33_quality)-1);

    ### PRINTING OUT SEQUENCES IN BASE SPACE
    if ($paired_end){
      print_sequences_out_basespace($seq_1,$phred33_quality,$count,$genomic_coords,$seq_2);
    }
    else{
      print_sequences_out_basespace($seq_1,$phred33_quality,$count,$genomic_coords,undef);
    }

    ### PRINTING OUT SEQUENCES IN COLOR SPACE
    if ($colorspace){
      if ($paired_end){
	print_sequences_out_colorspace ($seq_1_cs,$phred33_quality,$count,$genomic_coords,$seq_2_cs);
      }
      else{
	print_sequences_out_colorspace ($seq_1_cs,$phred33_quality,$count,$genomic_coords,undef);
      }
    }
  }

  warn "\nFinal report:\n";
  warn "-"x100,"\n";
  if ($random){
    warn "$count random sequences were successfully generated in total\n";
  }
  else{
    warn "$count genomic sequences were successfully generated in total (+ strand: $plus_strand_total\t - strand: $minus_strand_total)\n";
  }

  if ($number_of_SNPs > 0){
    if ($random){
      warn "Creating non-directional libraries was skipped as it doesn't appear to make sense for random sequences\n";
    }
    my $SNPs_per_sequence = $counting{'SNPs_introduced'}/$count;
    if ($paired_end){
      $SNPs_per_sequence /= 2;
    }
    warn "SNPs introduced per sequence: $SNPs_per_sequence ($counting{'SNPs_introduced'} in total)\n";
  }

  if ($non_directional){
    if ($random){
      warn "The introduction of SNPs was skipped as it doesn't make sense to introduce SNPs into random sequence\n";
    }
    my $percentage_non_directional = sprintf ("%.2f",$counting{'non_directional'}*100/$count);
    warn "Sequences reverse complemented (non-directional library): $counting{'non_directional'} ($percentage_non_directional%)\n\n";
  }

  if (defined $CG_conversion_rate and defined $CH_conversion_rate){
    my $percentage_CG_conversion_rate = sprintf ("%.2f",$counting{'CG_converted'}*100/$counting{'CG_total'});
    warn "Cytosines converted in CG-context: $percentage_CG_conversion_rate%\n";
    my $percentage_CH_conversion_rate = sprintf ("%.2f",$counting{'CH_converted'}*100/$counting{'CH_total'});
    warn "Cytosines converted in CH-context: $percentage_CH_conversion_rate%\n";
  }
  else{
    if ($conversion_rate == 0){
      warn "No bisfulfite conversion performed\n";
    }
    else{
      my $percentage_uniform_C_conversion = sprintf ("%.2f",$counting{'uniform_converted'}*100/$counting{'uniform_total'});
      warn "Cytosines bisulfite converted in any context: $percentage_uniform_C_conversion%\n";
    }
  }

  if ($variable_length_adapter){
    my $percent_small = sprintf ("%.1f",$counting{'small'}*100/$count);
    warn "$counting{'small'} elements were smaller than the sequence length $sequence_length ($percent_small%) and had some adapter sequence introduced\n";
  }
  if ($fixed_length_adapter){
    warn "The last $fixed_length_adapter of all sequences were replaced with adapter sequence\n";
  }

  unless ($error_rate == 0){
    my $percentage_errors_introduced = sprintf ("%.2f",($counting{'total_errors_introduced'}/$counting{'total_base_count'}*100));
    warn "Random sequencing errors introduced in total: $counting{'total_errors_introduced'} (of $counting{'total_base_count'} bp in total) (percentage: $percentage_errors_introduced)\n";

    if ($colorspace){
      my $percentage_errors_introduced_cs = sprintf ("%.2f",($counting{'total_errors_introduced_cs'}/$counting{'total_base_count_cs'}*100));
      warn "Random sequencing errors introduced into color space reads in total: $counting{'total_errors_introduced_cs'} (of $counting{'total_base_count_cs'} bp in total) (percentage: $percentage_errors_introduced_cs)\n";
    }
  }
}

sub create_normal_random_numbers{
  ### we'll generate a random length of a adapter contamination for each sequence
  ### To do this we will first simulate insert sizes with a normal distribution (and not a uniform distribution!)
  ### with a user specified mean fragment length (such as 150 or 200 bp)

  my $mu = $variable_length_adapter; # this is the mean of the bell curve
  my $sigma = 60; # this is the variance (height of the bell curve)

  warn "Now generating random fragment sizes with a normal distribution (using the Marsaglia polar method)\n";
  warn "Mean fragment size (mu):\t$mu\t(user-specified)\nVariance (sigma):\t$sigma\t(fixed)\n";

  foreach (1..$number_of_sequences){
    my $gauss = gaussian_rand();
    $gauss *= $sigma;
    $gauss = int($gauss+$mu);
    push @gaussian,$gauss;
  }
  warn "Generated ",scalar @gaussian," normally distributed random numbers\n\n";
}

sub introduce_fixed_length_adapter_contamination{

  my ($seq,$adapter_sequence) = @_;

  ### we'll generate a fixed length adapter contamination for each sequence with the length $fixed_length_adapter which was set
  ### with the option --fixed_length_adpater <int>

  my $sub_sequence = substr($adapter_sequence,0,$fixed_length_adapter);

  ### replacing the last bases of the sequence with the substitution sequence
  substr($seq,-$fixed_length_adapter,$fixed_length_adapter,$sub_sequence);

  return $seq;
}



sub introduce_variable_length_adapter_contamination{
  my ($seq_1,$seq_2,$adapter_sequence) = @_;
  # warn "Before seq1: ",length($seq_1)," bp long! $seq_1\n";
  # warn "Before seq2: ",length($seq_2)," bp long! $seq_2\n";

  # now taking a random fragment length from @gaussian
  my $fragment = shift @gaussian;
  my $seq_length = $sequence_length - 1; # the sequence has already been shortened by 1 bp again.

  die "Exiting for fragment $fragment\n"  unless (defined $fragment);

  if ($fragment < 0){
    $fragment = 0;
  }

  if ($fragment < $sequence_length){
    ++$counting{'small'};
    my $sub_length = $seq_length-$fragment;
    #  warn "sub length is: $sub_length\n";
    my $sub_sequence = substr($adapter_sequence,0,$sub_length);

    ### replacing the last bases of the sequence with the substitution sequence
    if ($paired_end){
      substr($seq_1,-$sub_length,$sub_length,$sub_sequence);
      substr($seq_2,-$sub_length,$sub_length,$sub_sequence);
      if (length$seq_1 < $seq_length){
	warn "The sequence is now only ",length($seq_1)," bp long! $seq_1\n";
      }
      if (length$seq_2 < $seq_length){
      	warn "The sequence is now only ",length($seq_2)," bp long! $seq_2\n";
      }

    }
    else{
      substr($seq_1,-$sub_length,$sub_length,$sub_sequence);
      if (length$seq_1 < $seq_length){
	warn "The sequence is now only ",length($seq_1)," bp long! $seq_1\n";
      }
    }
  }
  #warn "After seq1: ",length($seq_1)," bp. $seq_1\n";
  #warn "After seq2: ",length($seq_2)," bp. $seq_2\n";

  if ($paired_end){
    return ($seq_1,$seq_2);
  }
  else{
    return ($seq_1);
  }
}


sub gaussian_rand {
  ## this subroutine generates 2 independent random numbers with a uniform distribution and transforms them into
  ## 2 independent random numbers with a normal distribution

  my ($u1, $u2);  # uniformly distributed random numbers
  my $w;          # variance, then a weight
  my ($g1, $g2);  # gaussian-distributed numbers

  do {
    $u1 = 2 * rand() - 1;
    $u2 = 2 * rand() - 1;
    $w = $u1*$u1 + $u2*$u2;
  } while ( $w >= 1 ); ## this is important as it might otherwise produce illegal divisions by 0 in the ln step below

  $w = sqrt( (-2 * log($w))  / $w );
  $g1 = $u1 * $w;
  $g2 = $u2 * $w;

  # return both if wanted, else just one
  return $g1;
}



sub print_sequences_out_basespace{

  my ($seq_1,$qual,$count,$coord,$seq_2) = @_;

  if (defined $coord){ # reads simulated from a genome
    ### paired-end
    if (defined $seq_2){

      # warn length($seq_1),"\n";
      # warn length($seq_2),"\n";
      # warn length($qual),"\n\n";
      # sleep(1);


      print FASTQ_R1 "\@${count}_${coord}_R1\n";
      print FASTQ_R1 "$seq_1\n";
      print FASTQ_R1 "+\n";
      print FASTQ_R1 "$qual\n";

      print FASTQ_R2 "\@${count}_${coord}_R2\n";
      print FASTQ_R2 "$seq_2\n";
      print FASTQ_R2 "+\n";
      print FASTQ_R2 "$qual\n";
    }

    ### single-end
    else{
      # warn length($seq_1),"\n";
      # warn length($qual),"\n\n";
      # sleep(1);
      print FASTQ "\@${count}_${coord}\n";
      print FASTQ "$seq_1\n";
      print FASTQ "+\n";
      print FASTQ "$qual\n";
    }
  }

  else{ # random reads
  ### paired-end
    if (defined $seq_2){
      print FASTQ_R1 '@',$count,"_R1\n";
      print FASTQ_R1 "$seq_1\n";
      print FASTQ_R1 "+\n";
      print FASTQ_R1 "$qual\n";

      print FASTQ_R2 '@',$count,"_R2\n";
      print FASTQ_R2 "$seq_2\n";
      print FASTQ_R2 "+\n";
      print FASTQ_R2 "$qual\n";
    }

    ### single-end
    else{
      print FASTQ "\@${count}\n";
      print FASTQ "$seq_1\n";
      print FASTQ "+\n";
      print FASTQ "$qual\n";
    }
  }
}



sub print_sequences_out_colorspace{

  my ($seq_1,$qual,$count,$coord,$seq_2) = @_;

  ### converting the quality value back to Phred score (typical for colorspace
  my @quals = split (//,$qual);
  foreach my $index (0..$#quals){
    $quals[$index] = convert_quality_string_into_phred_score($quals[$index]);
  }
  $qual = join (" ",@quals);

  if (defined $coord){ # reads simulated from a genome

    ### paired-end
    if (defined $seq_2){
      print READS_R1 ">${count}_${coord}\n";
      print READS_R1 "$seq_1\n";
      print QUALS_R1 ">${count}_${coord}\n";
      print QUALS_R1 "$qual\n";

      print READS_R2 ">${count}_${coord}\n";
      print READS_R2 "$seq_2\n";
      print QUALS_R2 ">${count}_${coord}\n";
      print QUALS_R2 "$qual\n";
    }

    ### single-end
    else{
      print READS ">${count}_${coord}\n";
      print READS "$seq_1\n";
      print QUALS ">${count}_${coord}\n";
      print QUALS "$qual\n";
    }
  }

  else{ # random reads

  ### paired-end
    if (defined $seq_2){
      print READS_R1 ">$count\n";
      print READS_R1 "$seq_1\n";
      print QUALS_R1 ">$count\n";
      print QUALS_R1 "$qual\n";

      print READS_R2 ">$count\n";
      print READS_R2 "$seq_2\n";
      print QUALS_R2 ">$count\n";
      print QUALS_R2 "$qual\n";
    }

    ### single-end
    else{
      print READS ">$count\n";
      print READS "$seq_1\n";
      print QUALS ">$count\n";
      print QUALS "$qual\n";
    }
  }
}


sub bisulfite_transform_sequences_uniformly{

  my $total_C_count = 0;
  my $converted_C_count = 0;

  my $seq = shift;
 
  ### shortening the sequence again by 1bp
  $seq = substr($seq,0, (length($seq)-1));

  my @bases = split (//,$seq);

  foreach my $base (@bases){

    # only going to change Cs
    if ($base eq 'C'){
      ++$total_C_count;
      ### converting each C with an individual conversion rate (set globally)
      my $random = int(rand(10000)+1)/100;
	
      if ($random <= $conversion_rate){
	++$converted_C_count;
	$base = 'T';
      }
    }
  }

  $counting{'uniform_converted'} += $converted_C_count;
  $counting{'uniform_total'} += $total_C_count;

  my $bisulfite_converted_seq = join ("",@bases);

  return $bisulfite_converted_seq;
}


sub bisulfite_transform_sequences_context_specifically{

  my $seq = shift;

  my $converted_CG_count = 0;
  my $total_CG_count = 0;
  my $converted_CH_count = 0;
  my $total_CH_count = 0;

  my @bases = split (//,$seq);

  foreach my $index (0..$#bases){

    # only going to change Cs
    if ($bases[$index] eq 'C'){

      ### converting each C with an individual conversion rate (set globally for each context)
      my $random = int(rand(10000)+1)/100;
	
      ### if the C is at the last position we can't determine the sequence context (without going back to the genomic sequence) and will assume a non-CpG context for simplicity
      if ( ($index+1) >= scalar@bases){

	$total_CH_count++;

	if ($random <= $CH_conversion_rate){
	  $converted_CH_count++;
	  $bases[$index] = 'T';
	}
      }

      ### determining sequence context
      else{
	if ( $bases[$index+1] eq 'G'){
	  $total_CG_count++;
	  if ($random <= $CG_conversion_rate){
	    $bases[$index] = 'T';
	    $converted_CG_count++;
	  }
	}
	else {
	  ### non-CpG context
	  $total_CH_count++;
	  if ($random <= $CH_conversion_rate){
	    $bases[$index] = 'T';
	    $converted_CH_count++;
	  }
	}
      }
    }
  }

  $counting{'CG_converted'} += $converted_CG_count;
  $counting{'CG_total'} += $total_CG_count;
  $counting{'CH_converted'} += $converted_CH_count;
  $counting{'CH_total'} += $total_CH_count;

  my $bisulfite_converted_seq = join ("",@bases);

  ### shortening the sequence again by 1bp
  $bisulfite_converted_seq = substr($bisulfite_converted_seq,0, (length($bisulfite_converted_seq)-1));

  return $bisulfite_converted_seq;
}



sub make_non_directional_sequences{
  my $seq_1 = shift;
  # my $seq_2;
  my $rc = 0;

  my $random = int(rand(100)+1);

  if ($random <= 50){
    $rc = 1;
    if ($paired_end){
      #     $seq_1 =~ tr /CATG/GTAC/;
      #     $seq_2 =~ tr /CATG/GTAC/;
    }
    else{
      $seq_1 = reverse_complement($seq_1);
    }
    ++$counting{'non_directional'};
  }

  if ($paired_end){
    return $rc;
  }
  else{
    return $seq_1;
  }

}



sub introduce_SNPs{
  my $seq = shift;
  my $SNPs_introduced =0;
  my @bases = split (//,$seq);

  ### first determining the positions at which a SNP will be introduced
  my %snps;
  my $SNP_position_count = 0;

  while ($SNP_position_count < $number_of_SNPs){
    my $random= int(rand(length($seq))); # this will be a number between 0 and the read length-1, which we can use directly as index positions
    unless (exists $snps{$random}){
      $snps{$random} = 1;
      ++$SNP_position_count;
    }
  }

  # SNPs will be introduced at the positions stored in %snps
  foreach my $position (keys %snps){
    my $random = int(rand(3)+1); # will generate a random number between 1 and 3 which we will add to the number index of the number in the @DNA_bases array
    my $base_to_be_substituted = $bases[$position];

    if ($base_to_be_substituted eq 'A'){
      $random += 0;
    }
    elsif ($base_to_be_substituted eq 'T'){
      $random += 1;
    }
    elsif ($base_to_be_substituted eq 'C'){
	$random += 2;
      }
    elsif ($base_to_be_substituted eq 'G'){
      $random += 3;
    }
    else{
      die "base to be substituted was \"$base_to_be_substituted\"\n";
    }
    $random %= 4;
    ++$SNPs_introduced;
    $bases[$position] = $DNA_bases[$random];
  }

  my $substituted_sequence = join ("",@bases);
  $counting{'SNPs_introduced'} += $SNPs_introduced;
  return  $substituted_sequence;
}




sub introduce_sequencing_errors{

  my $total_base_count = 0;
  my $total_errors_introduced = 0;
  my $count = 0;
  my ($seq,$qual) = @_;

  my @bases = split (//,$seq);
  my @quals = split (//,$qual);

  unless(scalar@bases >= scalar @quals){
    die "The sequence length (",scalar@bases,") was shorter than the length of the quality string (",scalar@quals,") which mustn't happen!\n\n";
  }

  foreach my $index (0..$#quals){
    ++$total_base_count;
    my $phred_score = convert_quality_string_into_phred_score ($quals[$index]);
    my $error_rate = convert_phred_score_into_error_probability ($phred_score);

    my $random  = int(rand(10000)+1);
    $random /= 10000;

    if ($random < $error_rate){

      $random = int(rand(3)+1); # will generate a random number between 1 and 3 which we will add to the number index of the number in the @DNA_bases array

      if ($bases[$index] eq 'A'){
	$random += 0;
      }
      elsif ($bases[$index] eq 'T'){
	$random += 1;
      }
      elsif ($bases[$index] eq 'C'){
	$random += 2;
      }
      elsif ($bases[$index] eq 'G'){
	$random += 3;
      }
      else{
	warn "Found invalid base: \"$bases[$index]\"\n";
      }
      $random %= 4;

      # warn "replacing $bases[$index] with $DNA_bases[$random]\n";
      $bases[$index] = $DNA_bases[$random];

      ++$total_errors_introduced;
    }
  }
  my $substituted_sequence = join ("",@bases);
  # print "$seq\n$substituted_sequence\n$qual\n\n";
  $counting{'total_base_count'} += $total_base_count;
  $counting{'total_errors_introduced'} += $total_errors_introduced;

  return $substituted_sequence;
}



sub introduce_sequencing_errors_colorspace{

  my ($seq,$qual) = @_;

  my @colorspace_transitions = qw(0 1 2 3);

  my $total_base_count = 0;
  my $total_errors_introduced = 0;

  my @bases = split (//,$seq);
  my @quals = split (//,$qual);

  foreach my $index (0..$#quals){
    ++$total_base_count;
    my $phred_score = convert_quality_string_into_phred_score ($quals[$index]);
    my $error_rate = convert_phred_score_into_error_probability ($phred_score);

    my $random  = int(rand(10000)+1);
    $random /= 10000;

    if ($random < $error_rate){
      ++$total_errors_introduced;

      $random = int(rand(3)+1); # will generate a random number between 1 and 3 which we will add to the number index of the number in the @colorspace_transitions array

      ### in the special case that the index is 0 and we need to introduce a sequencing error we need to flip a base and not a colorspace transition
      if ($index == 0){
	if ($bases[$index] eq 'A'){
	  $random += 0;
	}
	elsif ($bases[$index] eq 'T'){
	  $random += 1;
	}
	elsif ($bases[$index] eq 'C'){
	  $random += 2;
	}
	elsif ($bases[$index] eq 'G'){
	  $random += 3;
	}
	else{
	  die "Starting base was $bases[$index]\n";
	}
	$random %= 4;
	# warn "replacing $bases[$index] with $DNA_bases[$random]\n";
	$bases[$index] = $DNA_bases[$random];
      }
      ### in all other cases we introduce a single colorspace transition error
      else{
	if ($bases[$index] eq '0'){
	  $random += 0;
	}
	elsif ($bases[$index] eq '1'){
	  $random += 1;
	}
	elsif ($bases[$index] eq '2'){
	  $random += 2;
	}
	elsif ($bases[$index] eq '3'){
	  $random += 3;
	}
	else{
	  die "base transition was $bases[$index]\n";
	}
	$random %= 4;
	#  warn "replacing $bases[$index] with $colorspace_transitions[$random]\n";
	$bases[$index] = $colorspace_transitions[$random];
      }
    }
  }
  my $substituted_sequence = join ("",@bases);

  $counting{'total_base_count_cs'} += $total_base_count;
  $counting{'total_errors_introduced_cs'} += $total_errors_introduced;

  return $substituted_sequence;
}


sub generate_quality_values{

  my ($var);

  ### NO ERROR RATE SPECIFIED
  if ($error_rate == 0){
      warn "Quality values will be constant throughout with a Phred score of $quality\n";
      
      my @quals;
      ### if no error rate was specified we will use a constant quality score for all bases ($quality), which was either determined by the user or which is 40 by default
      foreach (1..($sequence_length - 1)){ # sequence length has been incremented by 1
	  push @quals,$quality;
      }
      
      foreach my $qual(@quals){
	  $qual = convert_phred_score_into_quality_string($qual);
      }
      
      my $no_error_quality = join ("",@quals);
      return $no_error_quality;
  }

  ### ERROR RATE WAS SPECIFIED
  else{
    warn "Generating quality values with a user defined decaying per-bp error rate of $error_rate%\n";
    warn "Starting to work out the slope of the error curve\n";

    $var = determine_slope_of_the_error_rate_curve();

    warn "Error rates per bp will be modelled according to the formula:\n";
    warn "default base quality - 0.034286*position[bp] + 0.0009263*(position[bp]**2)) - 0.00001*(position[bp]**3)*$var)\n\n";

    my @quals;

    for my $x (1..($sequence_length - 1)){ # sequence length has been incremented by 1
      my $term1 = 0.034286*$x;
      my $term2 = 0.0009263*($x**2);
      my $term3 = $var*0.00001*($x**3);

      my $decayed_quality = $quality - $term1 + $term2 - $term3;
      if ($decayed_quality < 2){
	$decayed_quality = 2;
      }
      push @quals,$decayed_quality;
    }	

    ### converting the Phred Scale values into ASCII strings (currently Phred33 format)
    ### This will be performed for all error rate models

    foreach my $qual(@quals){
      $qual = convert_phred_score_into_quality_string($qual);
    }

    my $error_quality = join ("",@quals);
    return $error_quality;
  }
}


sub determine_slope_of_the_error_rate_curve{
  my $user_specified_error_rate = $error_rate/100;

  my $lower_limit = 1;  ## we start at 1 because this is a very flat curve
  my $upper_limit = 1000000; ## this is a curve with an extremely sharp drop
  my $old_lower_limit = $lower_limit;
  my $old_upper_limit = $upper_limit;

  my $var;
  my $count = 0;

  while(1){
    $count++;
    #  print "iteration $count\n";
    #  print "\nnew lower limit:\t$lower_limit\n";
    #  print "new upper limit:\t$upper_limit\n\n";

    # determining mean error rate for lower limit
    $var = $lower_limit;
    my $error_rate_lower_limit = get_mean_error_rate($var);
    #  warn "The mean error per basepair for the lower limit was:\t$error_rate_lower_limit\tfor \$var:\t$var\n";

    # determining mean error rate for upper limit
    $var = $upper_limit;
    my $error_rate_upper_limit = get_mean_error_rate($var);;
    #  warn "The mean error per basepair for the upper limit was:\t$error_rate_upper_limit\tfor \$var:\t$var\n";

    # determining mean error rate for the half distance

    my $half_distance = sprintf ("%.4f",($upper_limit-$lower_limit)/2);

    if ($user_specified_error_rate <= $error_rate_upper_limit){
      if ( ($error_rate_upper_limit-$user_specified_error_rate) <= 0.0001){
	$var = $upper_limit;
	last;
      }
      else{
	$old_upper_limit = $upper_limit;
	$old_lower_limit = $lower_limit;
	$upper_limit = $half_distance+$lower_limit;
      }
    }

    elsif ($user_specified_error_rate > $error_rate_upper_limit){
      if ( ($user_specified_error_rate-$error_rate_upper_limit) <= 0.0001 ){
	$var = $upper_limit;
	last;
      }
      else{
	# print "Set upper limit back from $upper_limit to $old_upper_limit\n";
	$upper_limit = $old_upper_limit;
	$half_distance = sprintf ("%.4f",($upper_limit-$lower_limit)/2);
	$lower_limit = $half_distance+$lower_limit;
	# print "Set lower limit from $old_lower_limit to $lower_limit\n";
      }
    }

    else{
      die "what else can there be? $user_specified_error_rate  $half_distance\n";
    }
  }
  return $var;
}


sub get_mean_error_rate{
  my $var = shift;
  #  print "using $var to calculate error rates\n";
  my @errors;

  ### error rates are calculated as means per bp per sequence length
  for my $x (1..$sequence_length){
    # this formula has been modelled from real data
    my $term1 = 0.034286*$x;
    my $term2 = 0.0009263*($x**2);
    my $term3 = 0.00001*$var *($x**3);

    my $decayed_quality = $quality - $term1 + $term2 - $term3;
    if ($decayed_quality < 2){
      $decayed_quality = 2;
    }
    #  print "Phred score: $decayed_quality\t";
    my $error_rate = sprintf("%.4f",convert_phred_score_into_error_probability($decayed_quality));
    # print "$error_rate\n";
    push @errors,$error_rate;
  }
  my $mean_error_rate;

  foreach my $rate(@errors){
    $mean_error_rate +=$rate;
  }
  $mean_error_rate /= scalar@errors;
  # print "mean error rate for \$var $var: $mean_error_rate\n";
  return $mean_error_rate;
}



sub convert_phred_score_into_quality_string{
  my $qual = shift;
  $qual = chr($qual+33);
  return $qual;
}

sub convert_quality_string_into_phred_score{
  my $string = shift;
  my $qual = ord($string)-33;
  return $qual;
}

sub convert_phred_score_into_error_probability{
  my $qual = shift;
  my $error_rate = 10**(-$qual/10);
  return $error_rate;
}



sub generate_genomic_sequences {

  my $sequence;
  my $coords;
  my $plus = 0;
  my $minus = 0;
  my $valid =0;
  
  until ($valid == 1){
    my $random = int(rand($total_genome_length)+1);
    my $chromosome_length = 0;

    # finding out which chromosome has been hit
    foreach my $chr (sort keys %chromosomes){
	$chromosome_length += length ($chromosomes{$chr});
	
	if ( ($random+length($sequence_length)) < $chromosome_length){
	    last unless (length $chromosomes{$chr} > $chromosome_length-$random+$sequence_length);
	    $sequence = substr ($chromosomes{$chr},$chromosome_length-$random,$sequence_length);
	    
	    # if the sequence contains any N's we are generating another random number without any Ns
	    last if ($sequence =~ /n/i);
	    last if (length($sequence) != $sequence_length);
	    
	    # otherwise we randomly choose either a forward or reverse sequence and then return it
	    my $strand = int(rand(2)); # will produce either 0 or 1 with a 50:50 chance
	    
	    if ($strand == 0){
		$sequence = reverse_complement($sequence);
		++$minus;
	    }	
	    else{
		++$plus;
	    }
	    
	    ++$valid;
	    
	    if ($plus == 1){
		$coords = "${chr}:".($chromosome_length-$random + 1).'-'.($chromosome_length - $random + $sequence_length - 1);  # shorten sequence by 1 on 3' end
	}
	else{
	  $coords = "${chr}:".($chromosome_length-$random + 1 + 1).'-'.($chromosome_length - $random + $sequence_length);  # shorten sequence by 1 on 5' end
	}
	last; # exiting once we found a valid sequence
      }
    }
  }
  if($plus == 1){
    return ($sequence,'plus',$coords);
  }
  else{
    return ($sequence,'minus',$coords);
  }
}

sub generate_genomic_sequences_paired_end {
    my $conversion_rate = shift;
    
    my $fragment_length = int(rand($maxfrag-$minfrag)+$minfrag);
    
    my $seq_1;
    my $seq_2;
    my $coords;
    my $plus = 0;
    my $minus = 0;
    my $valid = 0;
	# warn "fragment_length: $fragment_length\n";
    
    until ($valid){
		my $random = int(rand($total_genome_length)+1);
		# warn "\n\nNEW FRAGMENT:\nrandom: $random\n";
		# warn "fragment_length: $fragment_length\n";
    
		my $chromosome_length = 0;
		
		foreach my $chr (sort keys %chromosomes){
			$chromosome_length += length ($chromosomes{$chr});
			# warn "total chr length: $chromosome_length\n";
			
			if ( ($random+$fragment_length) < $chromosome_length){
			
				last unless ($chromosome_length - $fragment_length > $random );

				my $offset = $random - ($chromosome_length - length ($chromosomes{$chr}) );
				# warn "Offset: $offset\n";
				$seq_1 = substr ($chromosomes{$chr},$offset,$sequence_length);
				$seq_2 = substr ($chromosomes{$chr},$offset + $fragment_length - $sequence_length,$sequence_length);

				### we can only reverse complement seq_2 once the BS-conversion has taken place! (and after SNPs have been introduced)

				# if the sequences contain any N's we are generating another random number
				if ($seq_1 =~ /n/i or $seq_2 =~ /n/i){
					# warn "seq1 ($seq_1) or seq2 ($seq_2) contained N(s)\n";
					last;
				}
				if (length$seq_1 != $sequence_length or length$seq_2 != $sequence_length){
					# warn "The length of seq1 or seq2 were not equal to the sequence length of $sequence_length\n";
					last;
				}
			
				# otherwise we randomly choose either a forward or reverse strand for sequence 1 and return it
				my $strand = int(rand(2)); # will produce either 0 or 1 with a 50:50 chance
				
				if ($strand == 0){
					my $temp = reverse_complement($seq_1);
					$seq_1 = reverse_complement($seq_2);
					$seq_2 = $temp;
					++$minus;
					$coords = "${chr}:".($offset + 2).'-'.($offset + $fragment_length);       
				      
				}
				else{
					++$plus; # plus strand alignments are fine like this
					$coords = "${chr}:".($offset + 1).'-'.($offset + $fragment_length - 1);
				}

				# $coords = "${chr}:".($chromosome_length-$random+1).'-'.($chromosome_length-$random+$fragment_length);
				# warn "found one! Setting coords to $coords\n";
				++$valid;
				last; # exiting once we found a valid sequence pair
			}
			else{
				# warn "Random number ($random) + fragment length ($fragment_length) is beyond the end of the current chromosome\n";
			}
			# warn "Proceed to next chr\n\n";
		}
    }
    if($plus == 1){
	# warn "Returning coords: $coords, strand: +\n";
	return ($seq_1,$seq_2,'plus',$coords); 
    }
    else{
	# warn "Returning coords: $coords, strand: -\n";     
	return ($seq_1,$seq_2,'minus',$coords);
    }
}


sub generate_random_sequences {

  my @seq;

  for (1..$sequence_length){
    my $random = int(rand(4));
    push @seq, $DNA_bases[$random];
  }
  my $seq = join ("",@seq);

  return $seq;

}

sub read_genome_into_memory{

  ## reading in and storing the specified genome in the %chromosomes hash
  chdir ($genome_folder) or die "Can't move to genome folder $genome_folder: $!";
  print "Now reading in and storing sequence information of the genome specified in: $genome_folder\n\n";

  my @chromosome_filenames =  <*.fa>;

  ### if there aren't any genomic files with the extension .fa we will look for files with the extension .fasta
  unless (@chromosome_filenames){
    @chromosome_filenames =  <*.fasta>;
  }
  unless (@chromosome_filenames){
    die "The specified genome folder $genome_folder does not contain any sequence files in FastA format (with .fa or .fasta file extensions)\n";
  }

  foreach my $chromosome_filename (@chromosome_filenames){

    # skipping the tophat entire mouse genome fasta file
    next if ($chromosome_filename eq 'Mus_musculus.NCBIM37.fa');

    open (CHR_IN,$chromosome_filename) or die "Failed to read from sequence file $chromosome_filename $!\n";
    ### first line needs to be a fastA header
    my $first_line = <CHR_IN>;
    chomp $first_line;
    $first_line =~ s/\r//; # removing /r carriage returns

    ### Extracting chromosome name from the FastA header
    my $chromosome_name = extract_chromosome_name($first_line);
	
    my $sequence;
    while (<CHR_IN>){
      chomp;
      $_ =~ s/\r//; # removing /r carriage returns

      if ($_ =~ /^>/){
	### storing the previous chromosome in the %chromosomes hash, only relevant for Multi-Fasta-Files (MFA)
	if (exists $chromosomes{$chromosome_name}){
	  print "chr $chromosome_name (",length $sequence ," bp)\n";
	  die "Exiting because chromosome name already exists. Please make sure all chromosomes have a unique name!\n";
	}
	else {
	  if (length($sequence) == 0){
	    warn "Chromosome $chromosome_name in the multi-fasta file $chromosome_filename did not contain any sequence information!\n";
	  }
	  print "chr $chromosome_name (",length $sequence ," bp)\n";
	  $total_genome_length += length $sequence;
	  $chromosomes{$chromosome_name} = $sequence;
	}
	### resetting the sequence variable
	$sequence = '';
	### setting new chromosome name
	$chromosome_name = extract_chromosome_name($_);
      }
      else{
	$sequence .= uc$_;
      }
    }

    if (exists $chromosomes{$chromosome_name}){
      print "chr $chromosome_name (",length $sequence ," bp)\t";
      die "Exiting because chromosome name already exists. Please make sure all chromosomes have a unique name.\n";
    }
    else{
      if (length($sequence) == 0){
	warn "Chromosome $chromosome_name in the file $chromosome_filename did not contain any sequence information!\n";
      }
      print "chr $chromosome_name (",length $sequence ," bp)\n";
      $chromosomes{$chromosome_name} = $sequence;
      $total_genome_length += length $sequence;
    }
  }
  print "\n";
  chdir $parent_dir or die "Failed to move to directory $parent_dir\n";
}



sub extract_chromosome_name {
  ## Bowtie extracts the first string after the inition > in the FASTA file, so we are doing this as well
  my $fasta_header = shift;
  if ($fasta_header =~ s/^>//){
    my ($chromosome_name) = split (/\s+/,$fasta_header);
    return $chromosome_name;
  }
  else{
    die "The specified chromosome ($fasta_header) file doesn't seem to be in FASTA format as required!\n";
  }
}



sub reverse_complement{
  my $sequence = shift;
  $sequence =~ tr/CATG/GTAC/;
  my $rev_sequence = reverse($sequence);
  return $rev_sequence;
}



sub convert_basespace_to_colorspace{
  my $seq = shift;
  my @seq = split (//,$seq);

  my @cspace = 'T'; ### all color space reads start with a T

  my $first_base = 'T';
  my $second_base;

  foreach my $index (0..$#seq){

    $second_base = $seq[$index];

    if ($first_base eq 'A'){
      if ($second_base eq 'A'){
	push @cspace, 0;
      }
      if ($second_base eq 'C'){	
	push @cspace, 1;
      }
      if ($second_base eq 'G'){
	push @cspace, 2;
      }
      if ($second_base eq 'T'){
	push @cspace, 3;
      }
    }

    if ($first_base eq 'C'){
      if ($second_base eq 'A'){
	push @cspace, 1;
      }
      if ($second_base eq 'C'){	
	push @cspace, 0;
      }
      if ($second_base eq 'G'){
	push @cspace, 3;
      }
      if ($second_base eq 'T'){
	push @cspace, 2;
      }
    }

    if ($first_base eq 'G'){
      if ($second_base eq 'A'){
	push @cspace, 2;
      }
      if ($second_base eq 'C'){	
	push @cspace, 3;
      }
      if ($second_base eq 'G'){
	push @cspace, 0;
      }
      if ($second_base eq 'T'){
	push @cspace, 1;
      }
    }

    if ($first_base eq 'T'){
      if ($second_base eq 'A'){
	push @cspace, 3;
      }
      if ($second_base eq 'C'){	
	push @cspace, 2;
      }
      if ($second_base eq 'G'){
	push @cspace, 1;
      }
      if ($second_base eq 'T'){
	push @cspace, 0;
      }
    }

    $first_base = $second_base;

  }
  my $cspace_read = join ("",@cspace);
  return $cspace_read;
}



sub process_command_line{
	my $help;
	my $length;
	my $conversion_rate;
	my $snps;
	my $error_rate;
	my $random;
	my $genome_folder;
	my $fixed_length_adapter; ### replaces <int> bp at the end of each sequence
	my $variable_length_adapter;  ### replaces a variable amount of sequence at the end of some sequences
	my $adapter_dimer;  ### introduces <int> % of adapter dimers into the sequence simulation file
	my $number_of_seqs;
	my $quality;
	my $colorspace;
	my $non_directional;
	my $CG_conversion_rate;
	my $CH_conversion_rate;
	my $paired_end;
	my $minfrag;
	my $maxfrag;
	my $version;
	my $output_dir;

	my $command_line = GetOptions (
				'help|man'                   => \$help,
				'l|length=i'                 => \$length,
				'cr|conversion_rate=f'       => \$conversion_rate,
				'variable_length_adapter=i'  => \$variable_length_adapter,
				'fixed_length_adapter=i'     => \$fixed_length_adapter,
				'adapter_dimer=i'            => \$adapter_dimer,
				'e|error_rate=f'             => \$error_rate,
				'n|number_of_seqs=i'         => \$number_of_seqs,
				's|snps=i'                   => \$snps,
				'q|quality=i'                => \$quality,
				'random'                     => \$random,
				'colorspace'                 => \$colorspace,
				'genome_folder=s'            => \$genome_folder,
				'non_directional'            => \$non_directional,
				'CG|CG_conversion=f'         => \$CG_conversion_rate,
				'CH|CH_conversion=f'         => \$CH_conversion_rate,
				'pe|paired_end'              => \$paired_end,
				'I|minfrag=i'                => \$minfrag,
				'X|maxfrag=i'                => \$maxfrag,
				'version'                    => \$version,
				'output_dir=s'               => \$output_dir,
 				);


  ### EXIT ON ERROR if there were errors with any of the supplied options
  unless ($command_line){
    die "Please respecify command line options\n";
  }

  ### HELPFILE
  if ($help){
    print_helpfile();
    exit;
  }

  if ($version){
    print << "VERSION";

         Sherman - bisulfite-treated FastQ Read Simulator (biQRS)

       Sherman version: $sherman_version Copyright 2011-20 Felix Krueger
      Babraham Bioinformatics (felix.krueger\@babraham.ac.uk)
         www.bioinformatics.babraham.ac.uk/projects/sherman/
              https://github.com/FelixKrueger/Sherman

VERSION
    exit;
  }

  ##################################
  ### PROCESSING OPTIONS
  if (defined $length){
    if ($length == 0){
      warn "A sequence of 0 bp length? ... Please respecify!\n";
      print_helpfile();
      exit;
    }
    if ($length < 0 or $length > 300){
      warn "A sequence shorter than 0 bp or longer than 300bp? ... Please respecify!\n";
      print_helpfile();
      exit;
    }
  }
  else{
    warn "Please specify a sequence length!\n";
    sleep (2);
    print_helpfile();
    exit;
  }

	 ### OUTPUT DIRECTORY

	chdir $parent_dir or die "Failed to move back to current working directory\n";
	if ($output_dir){
		unless ($output_dir =~ /\/$/){
			$output_dir =~ s/$/\//;
		}

		if (chdir $output_dir){
			$output_dir = getcwd; #  making the path absolute
		}
		else{
			mkdir $output_dir or die "Unable to create directory $output_dir $!\n";
			warn "Created output directory $output_dir!\n\n";
			chdir $output_dir or die "Failed to move to $output_dir\n";
			$output_dir = getcwd; #  making the path absolute
		}
		
		unless ($output_dir =~ /\/$/){
			$output_dir =~ s/$/\//;
		}
		warn "Output will be written into the directory: $output_dir\n";
	}
	else{
		$output_dir = '';
	}

  
  
  ### BISULFITE CONVERSION RATES

  if (defined $CG_conversion_rate or defined $CH_conversion_rate){
    ## conversion rates need to be set for each context individually
    unless (defined $CG_conversion_rate and defined $CH_conversion_rate){
      die "Please specify conversion rates for both CG- and non-CG context\n\n";
    }
    if (defined $conversion_rate){
      die "Please select either a uniform bisulfite conversionrate (-cr/--conversion_rate <float>)\nOR individual context-dependent conversion rates (-CG/--CG_conversion <float>, -CH/--CH_conversion <float>)\n\n";
    }

    ### ensuring the conversion rates are within sensible limits
    unless ($CG_conversion_rate >= 0 and $CG_conversion_rate <= 100){
      die "Please specify a CG-conversion rate between 0 and 100\n";
    }
    unless ($CH_conversion_rate >= 0 and $CH_conversion_rate <= 100){
      die "Please specify a CH-conversion rate between 0 and 100\n";
    }
    ## setting the uniform conversionr ate to undef
    $conversion_rate = undef;
  }

  elsif (defined $conversion_rate){
    ### ensuring teh conversionr ate is within sensible limits
    unless ($conversion_rate >= 0 and $conversion_rate <= 100){
      die "Please specify a BS conversion rate value between 0 and 100\n";
    }

    $CH_conversion_rate = undef;
    $CG_conversion_rate = undef;
  }
  else{
    ## otherwise we assume a 100 % conversion rate
    $conversion_rate = "100";

    $CH_conversion_rate = undef;
    $CG_conversion_rate = undef;
  }


  ### NUMBER OF SEQUENCES TO BE SIMULATED
  if (defined $number_of_seqs){
    unless ($number_of_seqs > 0){
      die "Please select a sensible number of sequences to be generated (any positive integer, default = 1,000,000)\n";
    }
  }
  else {
    $number_of_seqs = 1000000;
  }

  ### ERROR RATE
  if (defined $error_rate){
    unless ($error_rate >= 0 and $error_rate <= 60){
      die "Please select an error rate between 0 and 60(%)!\n";
    }
  }
  else {
    $error_rate = 0;
  }

  ### SNPs TO BE INTRODUCED
  # if the user wants a certain amount of SNPs we are assuming the same Phred qualities for all bases, including the SNP positions

  if (defined $snps){

    die "The number of SNPs to be introduced can't be higher than the read length (and needs to be greater than 0)!\n" unless ($snps > 0 and $snps <= $length);

    if ($error_rate > 0){
      warn "Specifying an error rate and SNPs at the same time is not compatible. The error rate will be set to 0% and $snps SNPs will be introduced into the read.\nAll positions in the read will have the same basecall quality (which can be set with -q/--quality, 40 by default).\n\n";
    }

    $error_rate = 0;

  }

  else{
    $snps = 0;
  }

  ### RANDOM SEQUENCES INSTEAD OF MOUSE GENOME ONES
  unless ($random){
    $random = 0;
  }


  ### THE BASECALL QUALITY FOR READS WITHOUT ERROR RATE CAN BE SET MANUALLY

  if (defined $quality){
    unless ($quality >=2 and $quality <= 40){
      die "The quality values must be in the range of (Phred) 2-40! Please respecify\n";
    }
  }
  else{
    $quality = 40; ### this is the default
  }

  ### ADAPTER CONTAMINATION OPTIONS

  ### FIXED LENGTH ADAPTER
  if ($fixed_length_adapter){
    die "The adapter contamination must be shorter than the sequence length itself (and greater than 0). Please respecify\n" unless ($fixed_length_adapter > 0 and $fixed_length_adapter < $length);
    die "Fixed-length (all sequences) and variable-length (insert-size depenedent) adapter contaminations are mutually exclusive. Please select one of them only\n!" if (defined $variable_length_adapter);
    $variable_length_adapter = 0;
  }

  ### VARIABLE LENGTH ADAPTER
  if ($variable_length_adapter){
    unless ($variable_length_adapter >= 30 and $variable_length_adapter <= 400){
      die "The mean fragment length should be in the range of 30 to 400 (bp). Please respecify!\n\n";
    }
    $fixed_length_adapter = 0;
  }

  ### ADAPTER DIMER
  if (defined $adapter_dimer){
    unless ($adapter_dimer > 0 and $adapter_dimer <= 100){
      die "Adapter dimer contamination rate was selected as $adapter_dimer%. Please select something in the range of 1 to 100%!\n\n";
    }
  }
  else{
    $adapter_dimer = 0;
  }

  ### COLORSPACE
  unless ($colorspace){
    $colorspace = 0;
  }

  ### GENOME FOLDER
  if ($genome_folder){
    unless ($genome_folder =~/\/$/){
      $genome_folder =~ s/$/\//;
    }
    warn "Genome folder was specified as $genome_folder\n";
  }
  else{
    $genome_folder = '/bi/scratch/Genomes/Mouse/GRCm38/';
    warn "Using the default genome folder /bi/scratch/Genomes/Mouse/GRCm38/ \n";
  }

  ### NON-DIRECTIONAL BS-SEQ LIBRARIES
  unless ($non_directional){
    $non_directional = 0;
  }

  ### PAIRED-END READS
  if ($paired_end){

    # minimum fragment length
    unless (defined $minfrag){
      $minfrag = 70;
    }
    if ($minfrag < 0){
      die "A minimum fragment length shorter than 0 bp? ... Please respecify!\n";
    }

    # maximum fragment length
    unless (defined $maxfrag){
      $maxfrag = 400;
    }
    if ($maxfrag < 0 or $maxfrag > 2000){
      die "A maximum fragment length shorter than 0 bp or longer than 2000 bp? ... Please respecify!\n";
    }

    # fragment length checks
    if ($maxfrag <= $minfrag){
      die "Please select sensible fragment lengths (up to a maximum of 2000bp) (currently selected min: $minfrag/ max: $maxfrag)\n\n";
    }
    # if ( ($maxfrag-$minfrag) <= $length){
    #   die "Please select a fragment length that is longer than the read length\n\n";
    # }
  }
  else{
    $paired_end = 0;
    $minfrag = 0;
    $maxfrag = 0;
  }

  return ($length,$conversion_rate,$number_of_seqs,$error_rate,$snps,$quality,$fixed_length_adapter,$variable_length_adapter,$adapter_dimer,$random,$colorspace,$genome_folder,$non_directional,$CG_conversion_rate,$CH_conversion_rate,$paired_end,$minfrag,$maxfrag,$output_dir);
}

sub print_helpfile{
  print << 'HELP';


BASIC ATTRIBUTES:

-l/--length                       The length of all sequences to be generated (between 1 and 300). Has to be specified.

-n/--number_of_seqs               The number of sequences to be generated. Default: 1000000.

--genome_folder <path/to/folder>  Enter the genome folder you wish to use to extract sequences from. The genomic
                                  coordinates are printed into the read-ID line. Accepted formats are FastA files
                                  ending with '.fa' or '.fasta'. Default path: /bi/scratch/Genomes/Mouse/GRCm38/.
                                  Default: ON.

-o/--output_dir <dir>    		  Write all output files into this directory. By default the output files will be written into
                                  the current directory. If the specified folder does not exist, Sherman will attempt to
								  create it first. The path to the output folder can be either relative or absolute.								  

--random                          The sequences will be generated with entirely random base composition
                                  instead extracting sequences from a real genome. This is a much
                                  quicker option for testing purposes.

-q/--quality                      The default quality for all positions if error rate is set to 0% or if
                                  SNPs are to be introduced. Default: 40.

-pe/--paired_end                  Will create paired-end read files with the names simulated_1.fastq and
                                  simulated_2.fastq. The minimum and maximum fragment sizes can be adjusted
                                  with the options -I/--minfrag or -X/--maxfrag. Default: OFF.

-I/--minfrag <int>                The minimum size for paired-end fragments. Default: 70.

-X/--maxfrag <int>                The maximum size for paired-end fragments. Default: 400.

-cr/--conversion_rate <float>     A uniform bisulfite conversion rate of <float> %. This value can be anything
                                  between 0 (no bisulfite conversion at all) and 100% (all cytosines will be
                                  converted into thymines). To simulate standard genomic sequences for experiments
                                  other than BS-Seq simply use -cr 0.

-CG/--CG_conversion <float>       Bisulfite conversion rate for cytosines in CG-context as <float> %. This value
                                  can be anything between 0 (no bisulfite conversion at all) and 100% (all
                                  CG-cytosines will be converted into thymines). Requires -CH/--CH_conversion
                                  to be specified as well.

-CH/--CH_conversion <float>       Bisulfite conversion rate for cytosines in CH-context as <float> %. This value
                                  can be anything between 0 (no bisulfite conversion at all) and 100% (all
                                  CH-cytosines will be converted into thymines). Requires -CG/--CG_conversion
                                  to be specified as well.

--colorspace                     Using this option will print out all sequences in color space as well
                                  as in base space FastQ format. Note that the conversion of base space to
                                  colorspace takes place before any quality values or errors are introduced.

--non_directional                 The reads can orignate from any of the four possible strands produced by
                                  bisulfite conversion and PCR amplification. Default: OFF.


CONTAMINANTS:

-s/--snps <int>                   The number of SNPs to be introduced. This value can be anything between 1
                                  and the total sequence length. Default: 0. Introducing SNPs will always
                                  assume an error rate of 0%, the default quality for all bases can be
                                  specified with (-q/--quality).

-e/--error_rate <float>           The error rate in %. This can be anything between 0 and 60%. If the error
                                  rate is selected as 0%, no sequencing errors will be introduced (even though
                                  a Phred score of 40 formally translates into an error rate of 0.01%). The
                                  error rate will be a mean error rate per bp whereby the error curve follows
                                  an exponential decay model. This means that an error rate of 0.1% will
                                  - overall - introduce sequencing errors roughly every 1 in 1000 bases, whereby
                                  the 5' end of a read is much less likely to harbour errors than
                                  bases towards the 3' end.
                                  The process of working out the slope of the error curve should not take more than
                                  1 second, so if you seem to get stuck at this step please increase the error rate
                                  or decrease the read length (the curve fitting was done on ~2011 Illumina data
                                  and might not perform all that well on modern (2019+) data. Sorry about that.

--fixed_length_adapter <int>      Replaces the most 3' <int> bp of each read with Illumina adapter
                                  sequence. Sherman is currently using the Illumina Paired End PCR Primer 2
                                  as adapter sequence, however this can be modified in the script if necessary
                                  (locate the following line to change it: 
                                  my $adapter_sequence = 'CAAGCAGAAGACGGCATACGAGATCGGTCTCGGCATTCCTGCTGAACCGCTCTTCCGATCT').

--variable_length_adapter <int>   For this contamination we simulate a normal distribution of fragment
                                  sizes for a mean insert size specified as <int> bp and replace a
                                  variable portion at the 3' end of reads with a adapter sequence if the
                                  fragment size is smaller than the read length. A normal distribution
                                  of fragment sizes will be modelled using the specified <int> as mean
                                  (mu) and a variance (sigma) of 60 (this is a fixed value which was
                                  determined empirically).

Last update: 18 January 2019.


HELP
}
