#include<stdio.h>
int main(){
    double salary, increment;
    printf("Enter your salary: ");
    scanf("%lf", &salary);

    switch(salary < 10000){
        case 0:
            switch(salary > 50000){
                case 1:
                    increment = salary * .10;
                    salary = salary + increment;
                    printf("New salary: %.2f", salary);
                    break;
            }
            break;
        case 1:
            increment = salary * .25;
            salary = salary + increment;
            printf("New salary: %.2f", salary);
            break;
        default:
            salary = salary + 5000;
            printf("New salary: %.2f", salary);
            break;
    }
}