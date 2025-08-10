// multiplication table

#include<stdio.h>
int main(){
    int min, max;
    printf("Enter the min and max value: ");
    scanf("%d%d", &min, &max);

    for(min; min <= max; min++){
        for(int i = 1; i <= 10; i++){
        printf("%d * %d = %d\n", min, i, min * i);
        }
    }
    printf("\n");

    return 0;
}