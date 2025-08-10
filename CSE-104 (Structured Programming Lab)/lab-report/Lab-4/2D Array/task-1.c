// Write a C Program to Add Two Matrices Using Multi-dimensional Arrays.

#include <stdio.h>

int main() {
    int a[10][10], b[10][10], s[10][10], i, j, r, c;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter the elements of the first matrix: \n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the elements of the second matrix: \n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            s[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("The sum of the two matrices is: \n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }
    return 0;
}