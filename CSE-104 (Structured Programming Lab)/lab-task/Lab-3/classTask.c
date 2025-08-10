#include<stdio.h>

int main(){

    int options, n, num1, num2, num3, age, mark;
    char gen, op;
    double salary, increment;
    input:
    printf("Select your preferable option: \n");
    printf("Find the largest number between 2 number? \t\t\t\t\t\t press 1: \n");
    printf("Find a number is positive, negative or zero? \t\t\t\t\t\t press 2: \n");
    printf("Find the largest number between 3 number? \t\t\t\t\t\t press 3: \n");
    printf("Take a person's salary from user. Give him 25%% increment if his salary is less than \n10000. Give him 10%% increament if his salary is greater than 50000. Otherwise, \njust provide him a 5000 taka increment. Print his updated salary. \t\t\t press 4: \n");
    printf("Collect a person's age and gender. Print if he/she is eligible for marriage or not.  \t press 5: \n");
    printf("Collect a person's age. Print if he/she is eligible for voting or not.  \t\t press 6: \n");
    printf("Take an integer number from user. Print if the number is even-positive/odd-positive\n/even-negative/odd-negative?  \t\t\t\t\t\t\t\t press 7:  \n");
    printf("Take a student's math marks as input. Calculate his grade.  \t\t\t\t press 8: \n");
    printf("Design a simple calculator.  \t\t\t\t\t\t\t\t press 9: \n");
    scanf("%d", &options);

    switch(options){
        case 1:

            printf("Enter two integer number: ");
            scanf("%d%d", &num1, &num2);

            if(num1 > num2) printf("%d is the largest number.\n", num1);
            else printf("%d is the largest number.\n", num2);
            break;
        case 2:

            printf("Enter any integer number: ");
            scanf("%d", &n);

            if(n > 0) printf("%d is a positive number.\n", n);
            else if(n < 0) printf("%d is a negative number.\n", n);
            else if(n == 0) printf("%d is zero.\n", n);
            else printf("Wrong Input\n");
            break;
        case 3:

            printf("Enter 3 integer number: ");
            scanf("%d%d%d", &num1, &num2, &num3);

            if(num1 > num2 && num1 > num3) printf("%d is the largest number. \n", num1);
            else if(num2 > num1 && num2 > num3) printf("%d is the largest number. \n", num2);
            else printf("%d is the largest number.\n", num3);
            break;
        case 4:

            printf("Enter your salary: ");
            scanf("%lf", &salary);

            if(salary < 10000){
                increment = salary * .25;
                salary = salary + increment;
                printf("New salary: %.2f", salary);
            }else if(salary > 50000){
                increment = salary * .10;
                salary = salary + increment;
                printf("New salary: %.2f", salary);
            }else{
                salary = salary + 5000;
                printf("New salary: %.2f", salary);
            }
            break;
        case 5:

            printf("Enter your age: ");
            scanf("%d", &age);
            printf("If you are male type 'm' and if you are female type 'f'. ");
            printf("Choose your gender: \n");
            scanf(" %c", &gen);

            if(gen == 'f'){
                if(age >= 18) printf("You are eligible for marriage.\n");
                else printf("You are not eligible for marriage.\n");
            }else if(gen == 'm'){
                if(age >= 21) printf("You are eligible for marriage.\n");
                else printf("You are not eligible for marriage.\n");
            }else printf("Wrong Input.\n");

            break;
        case 6:

            printf("Enter your age: ");
            scanf("%d", &age);

            if(age >= 18) printf("You are eligible for voting.\n");
            else printf("You are not eligible for voting.\n");
            break;
        case 7:

            printf("Enter an integer number: ");
            scanf("%d", &n);

            if(n > 0){
                if(n % 2 == 0) printf("Even Positive\n");
                else printf("Odd Positive\n");
            }else{
                if(n % 2 == 0) printf("Even Negative\n");
                else printf("Odd Negative\n");
            }
            break;
        case 8:

            printf("Enter your math mark: ");
            scanf("%d", &mark);

            if(mark > 100 || mark < 0) printf("Wrong Input.\n");
            else if(mark >= 80 && mark <= 100) printf("You got A+\n");
            else if(mark >= 70 && mark <= 79) printf("You got A\n");
            else if(mark >= 60 && mark <= 69) printf("You got A-\n");
            else if(mark >= 50 && mark <= 59) printf("You got B\n");
            else if(mark >= 40 && mark <= 49) printf("You got C\n");
            else if(mark >= 33 && mark <= 39) printf("You got D\n");
            else printf("You Failed in the exam\n");
            break;
        case 9:

            printf("Enter your choice: +, -, *, /, %%: \n");
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
        }
        goto input;
    return 0;
}