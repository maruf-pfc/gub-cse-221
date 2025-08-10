/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 12-7-22
 * problem name			: Write a C program to calculate product of digits of any number.
 * problem description	: Write a C program to calculate product of digits of any number.
 */

#include <stdio.h>

int main() {

    int num;
    long long product=1ll;

    printf("Enter any number to calculate product of digit: ");
    scanf("%d", &num);

    product = (num == 0 ? 0 : 1ll);

    /* Repeat the steps till num becomes 0 */
    while(num != 0)
    {
        /* Get the last digit from num and multiplies to product */
        product = product * (num % 10);

        /* Remove the last digit from n */
        num = num / 10;
    }

    printf("Product of digits = %lld", product);

    return 0;
}