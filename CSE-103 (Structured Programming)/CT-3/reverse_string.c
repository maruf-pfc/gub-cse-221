// Write a C program that takes a string as input and reverses each of the word without using built in function

#include <stdio.h>

int main() {
    char str1[100], str2[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    int i = 0, j = 0;
    while (str[i] != '\0') {
        i++;
    }
    i--;
    while (i >= 0) {
        printf("%c", str[i]);
        i--;
    }
    printf("\n");
return 0;
}