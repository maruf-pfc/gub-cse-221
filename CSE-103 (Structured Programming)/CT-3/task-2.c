// Write a C program that takes a string as input and finds the length of that string using recursive function

#include <stdio.h>

int length(char str[]) {
    if (str[0] == '\0') {
        return 0;
    }
    return 1 + length(str + 1);
}

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    printf("Length of the string is %d\n", length(str));
    return 0;
}
