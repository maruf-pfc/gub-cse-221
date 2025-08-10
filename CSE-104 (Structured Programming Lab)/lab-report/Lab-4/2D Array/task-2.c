// Write a C program to Perform Matrix Multiplication.

#include <stdio.h>

int main() {
    int a[10][10], b[10][10], m[10][10], i, j, k, r1, c1, r2, c2;

    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter the elements of the first matrix: \n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter the elements of the second matrix: \n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    if (c1 != r2) {
        printf("The matrices cannot be multiplied.");
        return 0;
    }

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            m[i][j] = 0;
            for (k = 0; k < c1; k++) {
                m[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("The product of the two matrices is: \n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}