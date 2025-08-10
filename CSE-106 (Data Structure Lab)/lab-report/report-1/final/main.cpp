// Written by: Md. Maruf Sarker
// Platform: Arch Linux
// Problem: Binary Search (Use Bubble Sort to sort the elements)
// Language: cpp
// Date: 2022-10-26

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

// Function to sort the array using Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to search the key in the array using Binary Search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    // Variable Declaration and Initialization
    int n, i, j, temp, key, low, high, mid, flag = 0;

    // Input the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    // Declare an array of size n
    int arr[n];
    cout << "Enter the elements: ";

    // Input the elements from the user
    for (i = 0; i < n; i++)
        cin >> arr[i];

    // Sort the elements using Bubble Sort
    bubbleSort(arr, n);

    // Sorted array
    cout << "Sorted array: ";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";

    // Input the key to be searched
    cout << "\nEnter the key to be searched: ";
    cin >> key;

    // Binary Search
    int pos = binarySearch(arr, n, key);

    // Print the result
    if (pos == -1) cout << "Key not found!" << endl;
    else cout << "Key found at position " << pos + 1 << endl;
    
    return 0;
}