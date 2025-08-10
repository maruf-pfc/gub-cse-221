// Identity Matrix
#include<stdio.h>

int main(){
    int row, col, x, y;
    printf("Enter the number of row and col: ");
    scanf("%d%d", &row, &col);
    int matrix[row][col];

    if(row != col){
        printf("Not Identity Matrix.\n");
        return 0;
    }else{
        for(x = 0; x < row; x++){
            for(y = 0; y < col; y++){
                scanf("%d", &matrix[x][y]);
            }
        }
        for(x = 0; x < row; x++){
            for(y = 0; y < col; y++){
                if((x == y && matrix[x][y] == 1) || (x != y && matrix[x][y] == 0)){}
                else{
                    printf("Not Identity Matrix.\n");
                }
            }
        }
        printf("This is a Identity Matrix.\n");
    }

    return 0;
}