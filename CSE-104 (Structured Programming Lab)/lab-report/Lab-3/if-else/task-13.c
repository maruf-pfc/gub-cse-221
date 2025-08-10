/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 18-7-22
 * problem name			: Write a C Program to Check Whether a Character is a Vowel or
Consonant.
 */
#include<stdio.h>
int main(){
    char c;
    int lowercaseVowel, uppercaseVowel;

    printf("Enter an alphabet: ");
    scanf("%c", &c);

    lowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');

    uppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    if (lowercaseVowel || uppercaseVowel) printf("%c is a vowel.\n", c);
    else printf("%c is a consonant.\n", c);

    return 0;
}