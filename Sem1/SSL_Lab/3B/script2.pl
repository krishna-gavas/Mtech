#!/usr/bin/perl

sub num_sub{
    my @line = @_;
    open(filehandle2,">export1.txt");
    foreach $item (@line) {
        while($item =~ m/\d+\/\d+\/\d+/ ){
            print filehandle2 "$& \n";
            $item = $';
        }
    }
    close(filehandle2);
}


sub date_sub{
    my @line = @_;
    open(filehandle2,">export2.txt");
    foreach $item (@line) {
        while($item =~ m/[a-z.,\s]\d+[a-z.,\s]/ ){
            $item = $';
            $number = $&;
            $number =~ m/\d+/;
            print filehandle2 "$& \n";
        }
    }
    close(filehandle2);
}


open(filehandle1,"<import.txt") or die "Can't open file";
@lines = <filehandle1>;
close(filehandle1);

num_sub(@lines);
date_sub(@lines);


