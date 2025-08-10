// Written by: Md. Maruf Sarker
// Platform: Arch Linux
// Problem: Binary Search (Use Bubble Sort to sort the elements)
// Language: js
// Date: 2022-10-26

// Binary Search (Use Bubble Sort to sort the elements)

n = 5;
arr = [2, 4, 1, 3, 5];

// Bubble Sort
for (let i = 0; i < n; i++) {
    for (let j = 0; j < n - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            let temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
}

// Binary Search
let low = 0;
let high = n - 1;
let mid = Math.floor((low + high) / 2);
let key = 3;

while (low <= high) {
    if (arr[mid] == key) {
        console.log("Found");
        break;
    } else if (arr[mid] < key) {
        low = mid + 1;
    } else {
        high = mid - 1;
    }
    mid = Math.floor((low + high) / 2);
}

if (low > high) {
    console.log("Not Found");
}
