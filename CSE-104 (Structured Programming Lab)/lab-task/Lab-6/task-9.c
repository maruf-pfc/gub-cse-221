// Symmetric Matrix
#include<stdio.h>

int main(){
    int row1, col1, row2, col2, x, y, rowCounter, colCounter, isEqual = 1;
    printf("Enter the number of row and col: ");
    scanf("%d%d", &row1, &col1);
    int matrix[row1][col1];
    int tMatrix[col2][row2];

    // Receiving the value of the actual matrix
    for(x = 0; x < row1; x++){
        for(y = 0; y < col1; y++){
            scanf("%d", &matrix[x][y]);
        }
    }
    
    // Transpose the matrix
    for(int x = 0; x < row1; ++x){
        for(int y = 0; y < col1; ++y) {
            tMatrix[y][x] = matrix[x][y];
        }
    }
    /*  Compare size of both matrices. */
    if((row1 != row2)  || (col1 != col2)){
        printf("UNEQUAL MATRICES: Size of both matrices not same\n");
    } else {
        for(rowCounter=0; rowCounter<row1 && isEqual==1; rowCounter++){
            for(colCounter = 0; colCounter < col1; colCounter++){
                if(matrix[rowCounter][colCounter] != 
                        tMatrix[rowCounter][colCounter]){
                    printf("Not Symmetric Matrix.\n");
                    isEqual = 0;
                    break;
                }
            }
        }
        if(isEqual == 1){
            printf("Symmetric Matrix.\n");
        }
    }

    return 0;
}