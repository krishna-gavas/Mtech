#!/usr/bin/perl

my $filename = 'script5.pl';

my $newline = "​All rights reserved; M190448CS\n"; 
{                                                   #starts block of code to keep  @ARGV and $^I local to the block they are in
   local @ARGV = ($filename);                       #puts $file into the special array @ARGV
   local $^I = '.bac';                              #$^I (or $INPLACE_EDIT) tells perl that files processed by the <> construct are to be edited in-place
   while(<>){                                       #Perl will read from the @ARGV array and pass them into <> as filehandles
      if ($. == 2) {                                #$. the input record line number variable
         print "$newline$/";
      }
      else {
         print;
      }
   }
}

# use indirect filehandle, and 3 argument form of open
# open (my $handle, "+<", $filename) or die "Can't open file $filename : $!";

# @lines = <$handle>;

# seek $handle, 15, 0;

# print $handle "​\n";


# $flag = 0;
# foreach $item (@lines) {
#     if($flag == 1){
#         print $handle "​All rights reserved; M190448CS\n";
#         last;
#     }
#     if($item =~ m/^\#\!.*/ ){
#         $flag = 1;
#     }
# }
