/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 18-7-22
 * problem name			: Write a C program to design a simple CALCULATOR.
 */
#include<stdio.h>
int main(){
    int num1, num2;
    char op;

    printf("Enter your choice: +, -, *, /, %%: \n");
    scanf("%c", &op);

    printf("Enter two integer number: ");
    scanf("%d%d", &num1, &num2);

    int div = (float) num1 / num2;

    if(op == '+') printf("Summation = %d", num1 + num2);
    else if(op == '-') printf("Subtraction = %d", num1 - num2);
    else if(op == '*') printf("Multiplication = %d", num1 * num2);
    else if(op == '/') printf("Division = %d", div);
    else if(op == '%') printf("Modulus = %d", num1 % num2);
    else printf("Invalid operator");

    return 0;
}