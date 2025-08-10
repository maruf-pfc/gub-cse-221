// Written by: Md. Maruf Sarker
// Platform: Arch Linux
// Problem: Binary Search (Use Bubble Sort to sort the elements)
// Language: c
// Date: 2022-10-26

#include <stdio.h>

// Function to sort the array using Bubble Sort
void bubbleSort(int arr[], int n){
    int i, j, temp;
    for (i = 0; i < n; i++){
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to search the key in the array using Binary Search
int binarySearch(int arr[], int n, int key){
    int low = 0, high = n - 1, mid;
    while (low <= high){
        mid = (low + high) / 2;
        if (key == arr[mid]) return mid;
        else if (key < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

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
    bubbleSort(arr, n);

    // Sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Input the key to be searched
    printf("\nEnter the element to be searched: ");
    scanf("%d", &key);

    // Binary Search
    int pos = binarySearch(arr, n, key);

    // Print the result
    if (pos != -1) printf("Element found at position %d\n", pos + 1);
    else printf("Element not found\n");
    
    return 0;
}