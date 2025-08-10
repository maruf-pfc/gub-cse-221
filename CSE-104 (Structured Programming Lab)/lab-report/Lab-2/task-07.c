/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 28-6-22
 * problem name			: Swap the values of the variables with/without using any third variable.
 * problem description	: Swap the values of the variables with/without using any third variable.
 */

#include<stdio.h>

int main (){

    int num, reverse, x, y;

    printf("Enter two digit int number: ");
    scanf("%d", &num);

    x = num / 10;
    y = num % 10;
    reverse = (x * 1) + (y * 10);

    printf("Reversed Number = %d\n", reverse);
    
    return 0;
}
