#! /bin/bash
file1=$1
file2=$2

cut  -f 11 -d "," $file1  | sort | uniq | sed 's/[[:space:]].*//g'>>$file2