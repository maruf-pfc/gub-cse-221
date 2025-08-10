// copy a string to another string

#include <stdio.h>
#include <string.h>

int main(){
    char str1[50], str2[50];
    printf("Enter the first string: ");
    gets(str1);
    
    int x, i;
    for(x = 0; str1[x] != '\0'; x++);

    for(i = 0; str1[i] != '\0'; i++)
    {
        str2[i] = str1[i];
    }

    str2[i] = '\0';

    printf("Previous string: ");
    puts(str1);
    printf("Copied string: ");
    puts(str2);

    return 0;
}