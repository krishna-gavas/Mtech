#!/usr/bin/perl

@conjuction = ("And", "But", "For", "Nor", "Or", "So", "Yet","and", "but", "for", "nor", "or", "so", "yet");
@preposition = ("above", "across", "against", "along", "among", "around", "at", "before", "behind", "below", "beneath", "beside", "between", "by", "down", "from", "in", "into", "near", "of", "off", "on", "to", "toward", "under", "upon", "with", "within");

open(FILE,"<import2.txt");
undef($/); #sucks the entire file in at once
while(<FILE>){
	(@words)=split(/\s+/);	
}
close FILE;
for (@words){
	s/[\,|\.|\!|\?|\:|\;]//g; #removed punctuation
	$word{$_}++;
}

$count = 1;
foreach my $name ((sort { $word{$b} <=> $word{$a} } keys %word)) {
    if($count>10){
        last;
    }

    if( grep {$_ eq $name} @conjuction ){
        #nothing here
    }
    elsif( grep {$_ eq $name} @preposition ){
        #nothing here
    }
    else{
        printf ("%-8s %s\n", $name, $word{$name});
        $count = $count + 1;
    }

}
