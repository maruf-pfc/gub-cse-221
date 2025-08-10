// calculate armstrong number using function

#include<stdio.h>
#include<math.h>

int checkArmstrongNumber(int n){
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
    if(n == sum) printf("%d ", n);
}

int main(){
    int min, max;

    printf("Enter min & max value of the range: ");
    scanf("%d %d",&min, &max);

    for(min; min <= max; min++){
        int result = checkArmstrongNumber(min);
    }

  return 0;
}