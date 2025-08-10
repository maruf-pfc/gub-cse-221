// Take an integer number (2 <=x <= 10000) from user. Find the followings:
    // sum of digits of the number
    // Next prime number after the given number

#include<stdio.h>
int main(){
    int n;

    printf("Enter a number in the given range (2 <=x <= 10000): ");
    scanf("%d", &n);

    int temp = n;

    int rem, sum = 0, left;
    if(temp >= 2 && temp <= 10000){
        while(temp != 0){
            rem = temp % 10;
            sum += rem;
            temp /= 10;
        }
        printf("Sum of digits of the number: %d\n", sum);
    }else{
        printf("Your input is out of range\n");
    }

    // next prime number after the given number
    // check if the given number is prime or not
    
    // printf("%d\n", temp); // reinitialize temporary variable
    
    temp = n;
    if(temp >= 2 && temp <= 10000){

    for (int i = temp + 1; i <= 10000; ++i) {
        int flag = 0;

        for(int j = 2; j < i / 2; j++){
            if (i % j == 0) {
            flag = 1;
            break;
        }
        }

        if(flag == 0){
            printf("Next prime number is = %d\n", i);
            break;
        }
      }
    }else{
        printf("Your input is out of range\n");
    }

    return 0;
}
