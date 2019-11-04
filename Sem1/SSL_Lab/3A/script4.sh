# awk 'NR==FNR && /^[^#]/{a[FNR]=$0;next}$0==a[FNR] && /^[^#]/{print}' file2.txt file1.txt

awk 'FNR==NR{ A[$1]++; next}{ print $1 , A[$1]+0 }' file2.txt file1.txt
