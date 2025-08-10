# Write a Shell program to find the 2nd highest and 3rd highest numbers from a set of numbers and sum them using an array

#!/bin/bash

echo "Enter the number of elements: "
read n

# Initialize array to store numbers
declare -a v

sum=0

echo "Enter the numbers:"
for (( i = 0; i < n; i++ )); do
    read num
    v[i]=$num
done

# Sort the array in descending order
sorted_numbers=($(printf "%s\n" "${v[@]}" | sort -nr))

# Extract 2nd and 3rd highest numbers
second_highest=${sorted_numbers[1]}
third_highest=${sorted_numbers[2]}

# Calculate the sum of the 2nd and 3rd highest numbers
sum=$((second_highest + third_highest))

# Print the results
echo "2nd highest number: $second_highest"
echo "3rd highest number: $third_highest"
echo "Sum of 2nd and 3rd highest numbers: $sum"