// Write a program in C to convert decimal number to binary number using the function.

#include <stdio.h>

int dToB(int n){
    int binary = 0;
    int i = 1;
    while(n != 0){
        binary += (n % 2) * i;
        n /= 2;
        i *= 10;
    }
    return binary;
}

int main(){
    int n,i;
    printf("Enter the number to convert: ");
    scanf("%d",&n);

    printf("Binary of %d is %d\n", n, dToB(n));

return 0;
}