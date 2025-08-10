// Find all prime numbers in a given array.

#include <stdio.h>

int main() {
    int n, i, j;
    int array[100];
    int flag = 0;
    printf("Input the number of terms : ");
    scanf("%d", &n);

    for(i = 1;i <= n; i++){
        scanf("%d", &array[i]);
    }

    for(i = 1;i <= n; i++){
        for(j = 2;j <= array[i]/2; j++){
            if(array[i] % j == 0){
                flag = 1;
                break;
            }
        }
        if(flag == 0) printf("%d ",array[i]);
        flag = 0;
    }
    printf("\n");
    
    return 0;
}
