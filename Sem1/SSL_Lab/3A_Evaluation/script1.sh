#! /bin/bash
file1=$1
file2=$2

cut  -f 11 -d "," $file1  | sort | uniq -c | tail -n +2 | sort -r >>$file2

curdate=$(date +'%Y%m%d')

cut  -f 11 -d "," $file1  | sort | uniq -c | tail -n +2 | sort -r >>$file2.$curdate

