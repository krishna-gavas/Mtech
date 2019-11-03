#!/bin/bash

while getopts :p:m:d:f: options; do
    case $options in
        p) ap=$OPTARG;;
        m) bo=$OPTARG;;
        d) echo "I don't know what is $OPTARG";;
        f) echo "You chose 'f'";input="$OPTARG";;
        \?) exit 1 ;;
    esac
done

echo "option p = $ap and option m = $bo"
if [ "$input" = "" ]; then
    echo "No input"
else
    echo "input is $input"
fi