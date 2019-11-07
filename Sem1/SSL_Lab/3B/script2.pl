#!/usr/bin/perl

open(filehandle1,"<import.txt") or die "Can't open file";
@lines = <filehandle1>;
close(filehandle1);

open(filehandle2,">>export1.txt");

# foreach $item (@lines) {
#     $item  = chomp( $item );
#     if ( $item =~ m/\d\d/) {
#         my $number = $1;
#         print filehandle2 $number;
#     }
# }

foreach $item (@lines) {
    while($item =~ m/\d+\/\d+\/\d+/ ){
        print filehandle2 "$& \n";
        $item = $';
    }
}
