/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 5-7-22
 * problem name			: Write a c program to check weather a number is divisible by 5 and 11 or not.
 * problem description	: Write a c program to check weather a number is divisible by 5 and 11 or not.
 */

#include<stdio.h>
int main() {
    int n;

    printf("Enter an integer number: ");
    scanf("%d", &n);

    if(n % 5 == 0) printf("Yes, %d is divisible by 5\n", n);
    else if(n % 11 == 0) printf("Yes, %d is divisible by 11\n", n);
    else printf("No, %d is not divisible by 5 or 11\n", n);

    return 0;
}