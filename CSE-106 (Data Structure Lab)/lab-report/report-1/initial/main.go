// Written by: Md. Maruf Sarker
// Platform: Arch Linux
// Problem: Binary Search (Use Bubble Sort to sort the elements)
// Language: go
// Date: 2022-10-26

package main

import (
	"fmt"
)

func main() {
	var n, i, j, temp int
	var arr [100]int

	fmt.Print("Enter the number of elements: ")
	fmt.Scan(&n)

	fmt.Print("Enter the elements: ")
	for i = 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	// Bubble Sort
	for i = 0; i < n; i++ {
		for j = i + 1; j < n; j++ {
			if arr[i] > arr[j] {
				temp = arr[i]
				arr[i] = arr[j]
				arr[j] = temp
			}
		}
	}

	fmt.Print("Sorted array: ")
	for i = 0; i < n; i++ {
		fmt.Print(arr[i], " ")
	}

	// Binary Search
	var low, high, mid, key int
	low = 0
	high = n - 1
	mid = (low + high) / 2

	fmt.Print("\nEnter the key: ")
	fmt.Scan(&key)

	for low <= high {
		if arr[mid] < key {
			low = mid + 1
		} else if arr[mid] == key {
			fmt.Println("Found at position ", mid+1)
			break
		} else {
			high = mid - 1
		}
		mid = (low + high) / 2
	}

	if low > high {
		fmt.Println("Not found!")
	}
}