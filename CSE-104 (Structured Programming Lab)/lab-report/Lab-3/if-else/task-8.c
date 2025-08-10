/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 18-7-22
 * problem name			: Take a student's math marks as input. Calculate his grade.
 */
#include<stdio.h>
int main(){
    int mark;

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

    return 0;
}