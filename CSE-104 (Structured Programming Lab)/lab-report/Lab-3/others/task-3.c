/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 5-7-22
 * problem name			: Write a program to take the value from the user as input any alphabet and check weather it is vowel or consonatn(using the switch statement)
 * problem description	: Write a program to take the value from the user as input any alphabet and check weather it is vowel or consonatn(using the switch statement)
 */

#include <stdio.h>
int main(){
    char ch;

    printf("Enter any character: ");
    scanf("%c", &ch);

    switch(ch){
        case 'a':
            printf("%c is vowel\n", ch);
            break;
        case 'e':
            printf("%c is vowel\n", ch);
            break;
        case 'i':
            printf("%c is vowel\n", ch);
            break;
        case 'o':
            printf("%c is vowel\n", ch);
            break;
        case 'u':
            printf("%c is vowel\n", ch);
            break;
        default: 
            printf("%c is Consonant\n", ch);
            break;
    }

    return 0;
}