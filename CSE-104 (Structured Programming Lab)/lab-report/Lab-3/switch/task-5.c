/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 18-7-22
 * problem name			: Collect a person&#39;s age and gender. Print if he/she is eligible for voting
or not.
 * problem description	: Collect a person&#39;s age and gender. Print if he/she is eligible for voting
or not.
 */

#include<stdio.h>
int main(){
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);

    switch(age >= 18){
        case 0:
            printf("You are not eligible for voting.\n");
            break;
        case 1:
            printf("You are eligible for voting.\n");
            break;
    }
}