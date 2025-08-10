/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 18-7-22
 * problem name			: Collect a person's age and gender. Print if he/she is eligible for
marriage or not.
 */
#include<stdio.h>
int main(){
    int age;
    char gen;

    printf("Enter your age: ");
    scanf("%d", &age);
    printf("If you are male type 'm' and if you are female type 'f'. ");
    printf("Choose your gender: ");
    scanf(" %c", &gen);

    if(gen == 'f'){
        if(age >= 18) printf("You are eligible for marriage.\n");
        else printf("You are not eligible for marriage.\n");
    }else if(gen == 'm'){
        if(age >= 21) printf("You are eligible for marriage.\n");
        else printf("You are not eligible for marriage.\n");
    }else printf("Wrong Input.\n");

    return 0;
}