/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 18-7-22
 * problem name			: Print if the number is positive/negative/zero.
 * problem description	: Take a number from user. Print if the number is
positive/negative/zero.
 */
#include<stdio.h>
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if(n > 0){
        printf("%d is positive\n", n);
    }
    else if(n < 0){
        printf("%d is negative\n", n);
    }
    else{
        printf("%d is zero\n", n);
    }

    return 0;
}