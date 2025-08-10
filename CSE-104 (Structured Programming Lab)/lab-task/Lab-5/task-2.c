// write a c program to print the sum of digits of a given number

#include<stdio.h>
int main(){
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    int sum = 0, rem;

    int i = 0;
    while (n != 0) {
        rem = n % 10;
        n /= 10;
        sum = sum + rem;
    }
    printf("%d", sum);
    return 0;
}