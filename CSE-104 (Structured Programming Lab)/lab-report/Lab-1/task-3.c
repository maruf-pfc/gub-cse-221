/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 21-6-22
 * problem name			: Write a C Program to input two numbers as input and display its sum.
 * problem description	: Write a C Program to input two numbers as input and display its sum.
 */
#include<stdio.h>
int main() {
    int num1, num2;

    printf("Enter two int number: ");
    scanf("%d%d", &num1, &num2);

    printf("%d + %d = %d\n", num1, num2, num1 + num2);

    return 0;
}