// Written by: Md. Maruf Sarker
// Platform: Arch Linux
// Problem: Binary Search (Use Bubble Sort to sort the elements)
// Language: go
// Date: 2022-10-26

package main

import (
	"fmt"
)

// Function to sort the array using Bubble Sort
func bubbleSort(arr []int, n int) {
	for i := 0; i < n-1; i++ {
		for j := 0; j < n-i-1; j++ {
			if arr[j] > arr[j+1] {
				arr[j], arr[j+1] = arr[j+1], arr[j]
			}
		}
	}
}

// Function to search the key in the array using Binary Search
func binarySearch(arr []int, n int, key int) {
	low := 0
	high := n - 1
	mid := 0
	for low <= high {
		mid = (low + high) / 2
		if arr[mid] == key {
			fmt.Println("Found at index:", mid)
			return
		} else if arr[mid] < key {
			low = mid + 1
		} else {
			high = mid - 1
		}
	}
	fmt.Println("Not Found")
}

func main() {
	var n, i int
	var arr [100]int

	fmt.Print("Enter the number of elements: ")
	fmt.Scan(&n)

	fmt.Print("Enter the elements: ")
	for i = 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	// Bubble Sort
	bubbleSort(arr[:], n)

	fmt.Print("Sorted array: ")
	for i = 0; i < n; i++ {
		fmt.Print(arr[i], " ")
	}

	// Binary Search
	var key int

	fmt.Print("\nEnter the key: ")
	fmt.Scan(&key)

	binarySearch(arr[:], n, key)
}