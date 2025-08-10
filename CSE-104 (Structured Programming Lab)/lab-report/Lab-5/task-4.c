// Write a C program to find Length of the String by passing String / Character Array as an Argument using User Define Functions.

#include <stdio.h>

int strLength(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

int main() {
    char str[100];
    int length = 0;
    printf("Enter the string: ");
    scanf("%s", str);

    length = strLength(str);

    printf("The length of the string is %d\n", length);

return 0;
}