// Write a C program to find reverse of an array.

#include <stdio.h>

int main() {
    int a[10], i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = n - 1; i >= 0; i--) {
        printf("%d ", a[i]);
    }
    printf("\n");

return 0;
}