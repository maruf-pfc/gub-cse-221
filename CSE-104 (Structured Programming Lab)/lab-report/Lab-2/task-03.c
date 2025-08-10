/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 28-6-22
 * problem name			: Take 2 numbers from user. Find sum, sub, product, division, modulas between the 2 number.
 * problem description	: Take 2 numbers from user. Find sum, sub, product, division, modulas between the 2 number.
 */

#include <stdio.h>

int main()
{
    int num1, num2;
    float div;

    printf("Enter two integer number: ");
    scanf("%d%d", &num1, &num2);
    
    printf("Summation = %d\n", num1 + num2);
    printf("Subtraction = %d\n", num1 - num2);
    printf("Multiplication = %d\n", num1 * num2);
    printf("Division = %.2f\n", (float)num1 / (float)num2);
    printf("Modulas = %d\n", num1 % num2);

    return 0;
}