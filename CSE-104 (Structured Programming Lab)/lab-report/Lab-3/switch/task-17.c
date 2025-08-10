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

    switch (ch){
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        printf("Vowel\n");
        break;
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '0':
        printf("Digit\n");
        break;
    case '@':
    case '#':
    case '$':
    case '%':
    case '^':
    case '&':
    case '*':
    case '(':
    case ')':
    case '-':
    case '_':
    case '+':
    case '=':
    case '|':
    case '\\':
    case '{':
    case '}':
    case '[':
    case ']':
    case ':':
    case ';':
    case '<':
    case '>':
    case ',':
    case '.':
    case '/':
    case '?':
    case '~':
    case '`':
    case '!':
        printf("Special Symbol\n");
        break;
    default:
        printf("Consonant\n");
        break;
    }
    return 0;
}