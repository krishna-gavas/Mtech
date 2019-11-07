#!/usr/bin/perl

sub sum_sub{   
    $n = scalar(@_);
    $sum = 0;
    my @list = @_;
    foreach $item (@list) {
        $sum += $item;
    }
    
    return $sum;
}

sub avg_sub{
    my ($n, $sum) = (@_);
    $avg = $sum / $n;

    return $avg;
}

print "Enter the numbers: "; 
print "<Ctrl>-D to Terminate \n"; 
@nums = <STDIN>; 
  
# Removes new line appended at the end of every input 
chomp @nums; 
  
$sum = sum_sub(@nums);
print "Sum of the given numbers : $sum\n";

$avg = avg_sub(scalar(@nums), $sum);         # scalar(@nums) get total number of elements.
print "Average of the given numbers : $avg\n";