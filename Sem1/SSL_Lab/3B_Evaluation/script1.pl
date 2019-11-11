#!/usr/bin/perl

my $file = 'cricket.csv'; 
open(my $data, '<', $file) or die; 
  
my @teams;
while (my $line = <$data>)  
{ 
    chomp $line; 
 
    my @words = split(',', $line);   
    push @teams, $words[10];
}

foreach my $item (@teams) {
    $winCount{$item}++;
}

foreach my $team ((sort { $winCount{$b} <=> $winCount{$a} } keys %winCount)) {
    if( $team eq "" ){
        #nothing here
    }
    elsif( $team eq "winner" ){
        #nothing here
    }
    else{
        printf ("%s %s\n", $team, $winCount{$team});
    }
}