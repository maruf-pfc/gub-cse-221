// Write a program that will correctly decode a set of characters into a valid message. Your program should read a given file of a simple coded set of characters and print the exact message that the characters contain. The code key for this simple coding is a one for one character substitution based upon a single arithmetic manipulation of the printable portion of the ASCII character set.

#include <stdio.h>

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

    // decode the message
    char str[100];
    scanf("%[^\n]s", str);

    int i = 0;
    while (str[i] != '\0') {
        str[i] = str[i] - 7;
        i++;
    }

    printf("%s\n", str);
    return 0;
}