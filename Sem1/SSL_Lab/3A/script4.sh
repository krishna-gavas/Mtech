words=$(cat file2.txt  | wc -w)

awk -v total="$words" '
    BEGIN{
        FS=" " ; 
        count=0
    }

    FNR==NR && /^[^#]/{
        arr[FNR]=$0;
        next
    }
    {
        if ($0==arr[FNR]){
            count=count+NF
        }
        else{

        }
    }
    END{
        if(count/total > 0.8){
            print "There is Plagarism"
        }
        else{
            print "No plagarism"
        }
    }

' file1.txt file2.txt

# output=`expr $num1 + $num2`