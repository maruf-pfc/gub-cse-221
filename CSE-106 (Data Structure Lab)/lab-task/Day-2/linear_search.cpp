#include <iostream>
using namespace std;

int main(){
	int n;
	cout << "Enter the number of element you wanna add: ";
	cin >> n;
	int arr[n];
	
	// length of the array
	// int len = sizeof(arr)/sizeof(arr[0]);
	// take input from user
	cout << "Enter your array elements: ";
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int t;
	cout << "Enter your target value: ";
	cin >> t;
	int flag = 0, i = 0;
	for(i; i < n; i++){
		if(arr[i] == t){
			flag = 1;
			break;
		}	
		else flag = 0;
	}
	
	if(flag) cout << "Array element found on index " << i << endl;
	else cout << "Can't found your target value" << endl;
	return 0;
}
