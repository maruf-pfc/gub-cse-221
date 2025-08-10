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