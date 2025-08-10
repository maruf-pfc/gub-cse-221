// Written by: Md. Maruf Sarker
// Platform: Arch Linux
// Problem: Binary Search (Use Bubble Sort to sort the elements)
// Language: c
// Date: 2022-10-26

#include <stdio.h>

int main(){
    // Variable Declaration and Initialization
    int n, i, j, temp, key, low, high, mid, flag = 0;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Declare an array of size n
    int arr[n];
    printf("Enter the elements: ");

    // Input the elements from the user
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Sort the elements using Bubble Sort
    for (i = 0; i < n; i++){
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Input the key to be searched
    printf("\nEnter the element to be searched: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    // Binary Search
    while (low <= high){
        mid = (low + high) / 2;
        if (key == arr[mid]){
            flag = 1;
            break;
        }
        else if (key < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }

    // Print the result
    if (flag == 1) printf("Element found at position %d\n", mid + 1);
    else printf("Element not found\n");
    
    return 0;
}