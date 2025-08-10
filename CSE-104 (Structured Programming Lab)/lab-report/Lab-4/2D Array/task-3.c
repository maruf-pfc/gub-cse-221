// Write a C Program to Find Transpose of a Matrix.

#include<stdio.h>

int main(){
    int row, col, x, y;
    printf("Enter the number of row and col: ");
    scanf("%d%d", &row, &col);
    int matrix[row][col];
    int tMatrix[col][row];

    // Receiving the value of the actual matrix
    for(x = 0; x < row; x++){
        for(y = 0; y < col; y++){
            scanf("%d", &matrix[x][y]);
        }
    }
    
    // Transpose the matrix
    for(int x = 0; x < row; ++x){
        for(int y = 0; y < col; ++y) {
            tMatrix[y][x] = matrix[x][y];
        }
    }

    // Printing the transpose matrix
    printf("\nTranspose of the matrix:\n");
    for(x = 0; x < col; ++x){
        for(y = 0; y < row; ++y){
            printf("%d  ", tMatrix[x][y]);
            if (y == row - 1) printf("\n");
        }
    }

    return 0;
}