/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 18-7-22
 * problem name			: Take a person's salary from user. Give him 25% increment if his
salary is less than 10000. Give 10% increment if his salary is greater
than 50000. Otherwise, just provide him a 5000 taka increment. Print
his updated salary.
 */
#include<stdio.h>
int main(){
    double salary, increment;
    printf("Enter your salary: ");
    scanf("%lf", &salary);

    if(salary < 10000){
        increment = salary * .25;
        salary = salary + increment;
        printf("New salary: %.2f\n", salary);
    }else if(salary > 50000){
        increment = salary * .10;
        salary = salary + increment;
        printf("New salary: %.2f\n", salary);
    }else{
        salary = salary + 5000;
        printf("New salary: %.2f\n", salary);
    }
    return 0;
}