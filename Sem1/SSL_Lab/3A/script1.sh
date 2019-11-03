output=$(cat booklist.csv  | wc -l); 
drows=$((output-1))
output=$((output+1))
curdate=$(date +'%Y%m%d')
    
awk -v a="$output" ' BEGIN{FS="," ; failed = "a. valid"}!n{n = NF} NR < a && n!=NF{failed="a. invalid";exit}END{print failed}' booklist.csv

awk -v d="$drows" -v a="$output" ' BEGIN{FS="," ; failed = "c. invalid"} NR == a && $2 == d {failed="c. valid";exit}END{print failed}' booklist.csv

awk -v c="$curdate" -v a="$output" ' BEGIN{FS="," ; failed = "d. invalid"} NR == a && $1 == c {failed="d. valid";exit}END{print failed}' booklist.csv

