/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 18-7-22
 * problem name			: Take a student&#39;s math marks as input. Calculate his grade.
 */

#include<stdio.h>

int main(){
    int mark;

    printf("Enter your math mark: ");
    scanf("%d", &mark);

    switch(mark / 10){
        case 10:
        case 9:
        case 8:
            printf("You got A+\n");
            break;
        case 7:
            printf("You got A\n");
            break;
        case 6:
            printf("You got A-\n");
            break;
        case 5:
            printf("You got B\n");
            break;
        case 4:
            printf("You got C\n");
            break;
        case 3:
            switch(mark >= 33){
                case 0:
                    printf("You failed.\n");
                    break;
                case 1:
                    printf("You got D\n");
                    break;
            }
            break;
        case 2:
        case 1:
        case 0:
            printf("You failed\n");
            break;
        default:
            printf("Wrong Input.\n");
    }
    return 0;
}