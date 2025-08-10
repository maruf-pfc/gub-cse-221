#include<stdio.h>

int main(){
    int n, arr[100], i, sum = 0, count = 0;
    float avg = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
        count++;
    }
    avg = (float)sum / (float)count;

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", avg);

    return 0;
}