// Write a C program to find Sum of all Array Elements by passing array as an argument using User Define Functions.

#include <stdio.h>

int sumOfArray(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n, sum = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sum = sumOfArray(arr, n);
    printf("The sum of the array is %d\n", sum);

return 0;
}