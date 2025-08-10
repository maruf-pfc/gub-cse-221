// string concatination

#include <stdio.h>
#include <string.h>

int main(){
    char s1[50], s2[50];
    printf("Enter the first string: ");
    gets(s1);
    printf("Enter the second string: ");
    gets(s2);
    
    int x;
    for(x = 0; s1[x] != '\0'; x++);
    int y;
    for(y = 0; s2[y] != '\0'; y++, x++){
        s1[x] = s2[y];
    }
    s1[x] = '\0';
    puts(s1);
    
    return 0;
}