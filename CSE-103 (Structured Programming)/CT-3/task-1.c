// Write a C program that takes a string as input and reverses each of the word without using built in function

#include <stdio.h>

int main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    char str1[100], str2[100];
    printf("Enter a string: ");
    scanf("%s", str1);
    scanf("%s", str2);

    int i = 0, j = 0;
    // 1st string
    while (str1[i] != '\0') {
        i++;
    }
    i--;
    while (i >= 0) {
        printf("%c", str1[i]);
        i--;
    }
    printf(" ");

    // 2nd string
    while (str2[j] != '\0') {
        j++;
    }
    j--;

    while (j >= 0) {
        printf("%c", str2[j]);
        j--;
    }
    printf("\n");
return 0;
}