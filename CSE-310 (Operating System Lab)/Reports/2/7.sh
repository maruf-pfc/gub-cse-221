# Write a Shell program to find total number of alphabets, digits or special characters in a string.

#!/bin/bash

echo "Enter data: "
read -r s

alpha=0
digits=0
specialChar=0

for (( i = 0; i < ${#s}; i++ )); 
    do ch="${s:i:1}"
    if [[ $ch =~ [[:alpha:]] ]]; 
    then alpha=$((alpha + 1))
    elif [[ $ch =~ [[:digit:]] ]]; 
    then digits=$((digits + 1))
    else specialChar=$((specialChar + 1))
    fi
done

echo "Alphabets = $alpha"
echo "Digits = $digits"
echo "Special Characters = $specialChar"