# Write a shell program to display odd position numbers (using For loop).

#!/bin/bash

echo "Enter a 7-digit number:"
read number

if [[ ${#number} -ne 7 ]]; then
    echo "Invalid input. Please enter a 7-digit number."
    exit 1
fi

echo "Numbers at odd positions:"
for (( i = 0; i < ${#number}; i += 2 )); do
    echo "${number:i:1}"
done