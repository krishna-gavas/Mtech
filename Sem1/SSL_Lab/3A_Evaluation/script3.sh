#! /bin/bash

# cut  -f 14 -d "," 'cricket.csv'  | sort | uniq -c | tail -n +2 | sort -r

printf "Number_of_Times,Winning_Team,Player_Name\n" >> cicketOutput.csv

cut  -f 11,14 -d "," 'cricket.csv'  | sort | uniq -c | tail -n +2 | sort -r >> cicketOutput.csv

# export IFS=","

# cricket.csv | while read f1 f11; do echo "$f1:$f11"; done >> cicketOutput.csv