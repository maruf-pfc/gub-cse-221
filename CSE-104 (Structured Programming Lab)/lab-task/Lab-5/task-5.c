// calculate armstrong number using nested loop

#include<stdio.h>
#include<math.h>
int main(){
    int l, u, x;
    printf("Enter the min and max value: ");
    scanf("%d%d", &l, &u);

    int count, sum;

    for(x = l; x <= u; x++){
        count = 0;
        sum = 0;
        int temp = x;
        while(temp != 0){
            count++;
            temp /= 10;
        }
        temp = x;
        while(temp != 0){
            sum += pow(temp % 10, count);
            temp /= 10;
        }
        if(sum == x) printf("%d ", x);
    }

    return 0;
}