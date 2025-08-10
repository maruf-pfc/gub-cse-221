/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 18-7-22
 * problem name			: Take a character from keyboard. Check if the character is vowel/consonant/digit/special symbol.

Sample Input            Output
-----------------------------------
#                  Special Symbol
1                  digit
x                  consonant
E                  vowel
 */

#include<stdio.h>
#include <ctype.h>

int main(){
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    ch = tolower(ch);

    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        printf("Vowel\n");
    }else if(!(ch == 'a' && ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') && !(ch >= '0' && ch <= '9') && (isalpha(ch))){
        printf("Consonant\n");
    }else if(ch >= '0' && ch <= '9'){
        printf("Digit\n");
    }
    else{
        printf("Special Symbol\n");
    }
    
    return 0;
}