#!/usr/bin/perl
# my ($file) = @ARGV;
my $file = 'cricket.csv'; 
open(my $data, '<', $file) or die; 
  
my @teams;
while (my $line = <$data>)  
{ 
    chomp $line; 
 
    my @words = split(',', $line);   
    push @teams, $words[10];
}

# foreach my $item (@teams) {
#     $name{$item} = ;
# }

for (@teams){
	s/\s.*//g; 
	$team{$_} = $_;
}

foreach my $item ( keys %team) {
    if( $item eq "" ){
        #nothing here
    }
    elsif( $item eq "winner" ){
        #nothing here
    }
    else{
        printf ("%s\n", $item);
    }
        

}