// calculate strong number

#include<stdio.h>
#include<math.h>

int main(){
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    int temp = n, result, sum = 0, rem;

    while (temp != 0) {
        rem = temp % 10;
        temp /= 10;
        result = 1;
        for(int i = 1; i <= rem; i++) result *= i;
        sum += result;
    }

    if(sum == n) printf("Strong Number\n");
    else printf("Not a Strong Number.\n");
    return 0;
}
