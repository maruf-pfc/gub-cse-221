// CLP Questions

// Insert N items in an array. Find the followings:
    // Check if there is any duplicate element present in the array
    // Count total even/odd elements of the array.

#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int flag = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j])
                flag = 1;
        }
    }

    if(flag == 1) printf("Duplicate elements presents in your given array.\n");
    else printf("No duplicate elements found in this array.\n");


    // count total even or odd number in the given array.
    int even = 0, odd = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] % 2 == 0){
            even++;
        }else{
            odd++;
        }
    }

    printf("Total Even Numbers: %d\n", even);
    printf("Total Odd Numbers: %d\n", odd);


    return 0;
}
