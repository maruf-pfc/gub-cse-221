# Write a Shell program to Check Triangle is Valid or Not

#!/bin/bash

check_triangle() {
    echo "Enter the lengths of the three sides of the triangle: "
    read side1
    read side2
    read side3

    if [ $((side1 + side2)) -gt $side3 ] && [ $((side1 + side3)) -gt $side2 ] && [ $((side2 + side3)) -gt $side1 ]; then
        echo "The triangle is valid."
    else
        echo "The triangle is not valid."
    fi
}

check_triangle