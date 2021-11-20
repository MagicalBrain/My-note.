#!/usr/bin/perl
use warnings FATAL => 'all';    #use声明加载模块
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
