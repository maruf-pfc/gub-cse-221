// compare two strings.

#include<stdio.h>
 
int main() {
    char s1[100], s2[100];
    int i = 0;
 
    printf("Enter two strings: ");
    gets(s1);
    gets(s2);

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') i++;

    if (s1[i] > s2[i])
        printf("String1 is greater than String2");
    else if (s1[i] < s2[i])
        printf("String1 is less than String2");
    else
        printf("Strings are equal.\n");
 
   return 0;
}