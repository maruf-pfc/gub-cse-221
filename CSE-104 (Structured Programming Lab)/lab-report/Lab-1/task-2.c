/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 21-6-22
 * problem name			: Write a C program to input two numbers and display those numbers.
 * problem description	: Write a C program to input two numbers and display those numbers.
 */
#include<stdio.h>
int main() {
    int num1, num2;

    printf("Enter two int number: ");
    scanf("%d%d", &num1, &num2);

    printf("Your 1st given number = %d\n", num1);
    printf("Your 2nd given number = %d\n", num2);

    return 0;
}