// Written by: Md. Maruf Sarker
// Platform: Arch Linux
// Problem: Binary Search (Use Bubble Sort to sort the elements)
// Language: cpp
// Date: 2022-10-26

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

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
    cout << "Sorted array: ";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";

    // Input the key to be searched
    cout << "\nEnter the key to be searched: ";
    cin >> key;

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
    if (flag == 1) cout << "Key found at position " << mid + 1 << endl;
    else cout << "Key not found" << endl;
    
    return 0;
}