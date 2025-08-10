#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int t, int low, int high){
	while(low <= high){
		int mid = (low + high) / 2;
		
		if(arr[mid] == t) return mid;
		if(arr[mid] < t) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}

int main(){
	int n;
	cout << "Enter the number of element you wanna add: ";
	cin >> n;
	int arr[n];
	
	cout << "Enter your array elements: ";
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int t;
	cout << "Enter your target value: ";
	cin >> t;
	
	// binary search
	int result = binarySearch(arr, t, 0, n);
	
	// print the index...
	return 0;
}
