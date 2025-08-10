// reverse a string

#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    printf("Enter a string: ");
    gets(str);

    int x;
    for(x = 0; str[x] != '\0'; x++);

    int length = x - 1;

    int a = 0, b = length;
    char temp;
    while(a < b){
        
        temp = str[a];
        str[a] = str[b];
        str[b] = temp;
        
        a++;
        b--;
    }
    puts(str);
    return 0;
}