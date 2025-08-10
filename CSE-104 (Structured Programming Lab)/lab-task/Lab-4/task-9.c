#include<stdio.h>

int main(){
    int num1, num2;
    char op;

    printf("Enter your choice: +, -, *, /, %%: ");
    scanf("%c", &op);
    printf("Enter two integer number: ");
    scanf("%d%d", &num1, &num2);

    switch(op){
        case '+':
            printf("Summation = %d\n", num1 + num2);
            break;
        case '-':
            printf("Subtraction = %d\n", num1 - num2);
            break;
        case '*':
            printf("Multiplication = %d\n", num1 * num2);
            break;
        case '/':
            printf("Division = %.2f\n", (float)num1 / (float)num2);
            break;
        case '%':
            printf("Modulas = %d\n", num1 % num2);
            break;
        default:
            printf("Wrong Input\n");
    }

    return 0;
}