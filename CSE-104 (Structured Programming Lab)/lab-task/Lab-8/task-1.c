// length of a string

#include <stdio.h>
#include <string.h>

int main(){
    char str[50];
    printf("Enter the first string: ");
    gets(str);
    
    int x;
    for(x = 0; str[x] != '\0'; x++);

    puts(str);

    return 0;
}