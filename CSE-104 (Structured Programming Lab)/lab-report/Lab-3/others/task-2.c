/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 5-7-22
 * problem name			: Write a c program to find maximum between three numbers.
 * problem description	: Write a c program to find maximum between three numbers.
 */

#include<stdio.h>
int main() {
    int num1, num2, num3;

    printf("Enter 3 integer number: ");
    scanf("%d%d%d", &num1, &num2, &num3);

    if(num1 > num2 && num1 > num3) printf("%d is the maximum of three number\n", num1);
    else if(num2 > num1 && num2 > num3) printf("%d is the maximum of three number\n", num2);
    else printf("%d is the maximum of three number\n", num3);

    return 0;
}