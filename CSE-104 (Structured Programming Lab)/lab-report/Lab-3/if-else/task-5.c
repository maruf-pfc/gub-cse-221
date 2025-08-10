/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 18-7-22
 * problem name			: Collect a person's age and gender. Print if he/she is eligible for voting
or not.
 */
#include<stdio.h>
int main(){
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if(age >= 18) printf("You are eligible for voting.\n");
    else printf("You are not eligible for voting.\n");
    return 0;
}