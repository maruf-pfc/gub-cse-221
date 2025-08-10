/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 18-7-22
 * problem name			: Take two numbers from user. Find the largest number.
 * problem description	: Take two numbers from user. Find the largest number.
 */

#include<stdio.h>
int main(){
    int num1, num2;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    switch (num1 > num2) {
        case 1:
            printf("%d is the largest number\n", num1);
            break;
        case 0:
            printf("%d is the largest number\n", num2);
            break;
        default:
            printf("Wrong Input\n");
            break;
    }

    return 0;
}