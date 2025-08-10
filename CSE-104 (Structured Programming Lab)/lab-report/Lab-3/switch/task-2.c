/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 18-7-22
 * problem name			: Take a number from user. Print if the number is positive/negative/zero.
 * problem description	: Take a number from user. Print if the number is positive/negative/zero.
 */
#include<stdio.h>
int main(){
    int n;
    printf("Enter an integer number: ");
    scanf("%d", &n);

    switch(n >= 0){
        case 0:
            printf("%d is a negative number.\n", n);
            break;
        case 1:
            switch(n == 0){
                case 0:
                    printf("%d is a positive number.\n", n);
                    break;
                case 1:
                    printf("%d is zero.\n", n);
                    break;
            }
            break;
        default:
            printf("Wrong Input\n");
            break;
    }
}