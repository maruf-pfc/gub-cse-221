# Write a Shell program using while loop:

#!/bin/bash

echo "Enter the number:"
read number

size=${#number}

i=0
while [ $i -le 9 ]; 
    do
    cnt=0
    for (( j=0; j<$size; j++ )); 
    do
        digit="${number:$j:1}"
        if [ $digit -eq $i ]; 
        then cnt=$((cnt + 1))
        fi
    done
    if [ $cnt -ne 0 ]; 
    then echo "$i = $cnt times"
    fi
    i=$((i + 1))
done