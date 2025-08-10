# Write a Shell program to find the factorial of two different numbers and sum of the numbers using a function.

#!/bin/bash

factorial() {
    local n=$1
    local ans=1
    for (( i = 1; i <= n; i++ )); 
    do ans=$((ans * i))
    done
    echo "$ans"
}

main() {
    echo "Enter 2 numbers:"
    read n1 n2

    fact_n1=$(factorial $n1)
    fact_n2=$(factorial $n2)

    sum=$((fact_n1 + fact_n2))
    echo "Sum = $sum"
}

main