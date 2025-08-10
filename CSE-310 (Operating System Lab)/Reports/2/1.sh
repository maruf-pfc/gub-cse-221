# Write a Shell program to find the sum of odd and even numbers from a set of numbers.

#!/bin/bash

is_odd() {
    if (( $1 % 2 != 0 ));
    then return 0
    else return 1
    fi
}

odd_sum=0
even_sum=0

echo "Enter the size of the array:"
read size

echo "Enter the values of the array:"
for ((i = 0; i < size; i++)); do
    read num
    numbers[i]=$num
done

for num in "${numbers[@]}"; do
    if is_odd "$num";
    then odd_sum=$((odd_sum + num))
    else even_sum=$((even_sum + num))
    fi
done

echo "Sum of odd numbers: $odd_sum"
echo "Sum of even numbers: $even_sum"
