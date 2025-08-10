#include<stdio.h>
int main (){

    int num, reverse, x, y;

    printf("Enter two digit int number: ");
    scanf("%d", &num);

    x = num / 10;
    y = num % 10;
    reverse = (x * 1) + (y * 10);

    printf("Reversed Number = %d", reverse);
    
    return 0;
}