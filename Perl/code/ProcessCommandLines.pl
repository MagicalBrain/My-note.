#!/usr/bin/perl

#use warnings FATAL => 'all';
#use strict;
#use Cwd;
use Getopt::Long; # 这个是包含process_command_lines() 的包

my ($name, $nickname) = process_command_line();

print "$name, $nickname";

sub process_command_line{
	my $name;
    my $nickname;

	my $command_line = GetOptions (
				'name'                   => \$name,
				'nickname'               => \$nickname
 				);

  ### EXIT ON ERROR if there were errors with any of the supplied options
  unless ($command_line){
    die "Please respecify command line options\n";
  }

  ### HELPFILE
  if ($name){
    print "徐丹同\n";
    
  }

  if ($nickname){
    print "徐铁蛋\n";
    exit;
  }

  #return ($name, $nickname); # 返回参数
}
