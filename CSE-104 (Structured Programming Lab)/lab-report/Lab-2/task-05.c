/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 28-6-22
 * problem name			: Take a two digit number from user. Print the reverse of the number.
 * problem description	: Take a two digit number from user. Print the reverse of the number.
 */

#include<stdio.h>
int main (){

    int num, reverse, x, y;

    printf("Enter two digit int number: ");
    scanf("%d", &num);

    x = num / 10;
    y = num % 10;

    printf("Reversed Number = %d%d\n", y,x);
    
    return 0;
}