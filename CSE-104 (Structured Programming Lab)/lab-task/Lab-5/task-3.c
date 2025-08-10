// c program to check if a given number is armstrong or not

#include<stdio.h>
#include<math.h>
int main(){
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    int temp = n, count = 0, sum = 0;

    while (temp != 0) {
        temp /= 10;
        count++;
    }
    temp = n;
    while(temp != 0){
        sum += pow(temp % 10, count);
        temp /= 10;
    }

    if(sum == n) printf("%d is Armstrong Number.\n", n);
    else printf("%d is not a Armstrong Number.\n", n);
    // printf("%d", count);
    return 0;
}

// suggesstion for midterm

// perfect number
// strong number
// armstrong number
// prime number