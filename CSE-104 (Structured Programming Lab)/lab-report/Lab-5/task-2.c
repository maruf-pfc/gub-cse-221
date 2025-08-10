// Write a program in C to get the largest element of an array using the function.

#include <stdio.h>

int lgElement(int arr[], int n){
    int i, max = arr[0];
    for(i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int n, max = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    max = lgElement(arr, n);
    printf("The largest element of the array is %d\n", max);

return 0;
}