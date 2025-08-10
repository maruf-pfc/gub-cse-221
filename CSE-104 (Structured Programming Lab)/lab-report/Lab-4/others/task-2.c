/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 12-7-22
 * problem name			: Write a C program to swap first and last digits of any number.
 * problem description	: Write a C program to swap first and last digits of any number.
 */

#include<stdio.h>
int main (){

    int num, first, last, sum, swap;

    printf("Enter your number: ");
    scanf("%d", &num);

    // get the last number
    last = num % 10;
    first = num;

    // get the first number deviding it by 10 until num is greater or equal 10
    while(num >= 10){
        num = num / 10;
    }
    first = num;

    // swap number
    swap = (first * 1) + (last * 10);

    printf("Swap Number of 1st and last digit = %d", swap);
    
    return 0;
}