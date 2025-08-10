// Write a C program to swap the values of two variables without using a temporary variable.

#include <stdio.h>
int main(){
    int a, b;
    printf("Enter two integer numbers: ");
    scanf("%d%d", &a, &b);

    printf("Previous:\n");
    printf("number 1 = %d\nnumber 2 = %d\n", a,b);

    a = a + b;
    b = a - b;
    a = a - b;
/*
    // explanation
    let,
    a = 3
    b = 4

    a = a + b = 3 + 4 = 7
    b = a - b = 7 - 4 = 3
    a = a - b = 7 - 3 = 4

*/
    printf("Now:\n");
    printf("number 1 = %d\nnumber 2 = %d\n", a,b);

    return 0;
}
