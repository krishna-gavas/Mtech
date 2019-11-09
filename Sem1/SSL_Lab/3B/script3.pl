#!/usr/bin/perl

open(filehandle1,"+<import.txt") or die "Can't open file";
@lines = <filehandle1>;
chomp @lines;

open(filehandle2,">export3.txt");
foreach $item (@lines) {
    $newitem = $item;
    while($item =~ m/\d+\/\d+\/\d+/ ){
        my ($date, $month, $year) = ($item =~ m/(\d+)\/(\d+)\/(\d+)/);
        $newitem =~ s/$date\/$month\/$year/$month\/$date\/$year/g;

        $item = $';
    }
    print filehandle2 "$newitem \n";
}
close(filehandle2);
close(filehandle1);


