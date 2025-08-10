// Take n numbers in an array and print the sum and average of the n numbers.

#include <stdio.h>

int main() {
    int n, i;
    long sum = 0;
    float average;
    int array[100];
    
    printf("Input the number of terms : ");
    scanf("%d", &n);
    
    for(i = 1;i <= n; i++){
        scanf("%d", &array[i]);
        sum += array[i];
    }
    average = sum / n;
    printf("The Sum is : %ld\n",sum);
    printf("The Average is : %.2f\n",average);
    
    return 0;
}
