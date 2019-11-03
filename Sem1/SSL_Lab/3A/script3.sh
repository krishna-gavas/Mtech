#!/bin/bash

while getopts :p:m:d:f: options; do
    case $options in
        p) ap=$OPTARG;;
        m) bm=$OPTARG;;
        d) cd=$OPTARG;;
        f) df=$OPTARG;;
        \?) exit 1 ;;
    esac
done
 

if [ "$ap" = "" ]; then
    ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%mem | head
    printf "\n\n\n"
else
    echo "no -p"
fi

if [ "$bm" = "" ]; then
    df -aTh
    printf "\n\n\n"
else
    echo "no -m"
fi

if [ "$cd" = "" ]; then
    df -H | cut -d'%' -f1 | awk '$5 > 90{print $0}'
    printf "\n\n\n"
else
    echo "no -d"
fi