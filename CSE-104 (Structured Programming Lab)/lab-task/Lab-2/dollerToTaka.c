// 1 USD = 91.35BDT
#include <stdio.h>
int main(){
    float taka, doller;

    printf("Enter Your Amount(BDT) = ");
    scanf("%f", &taka);

    doller = taka / 91.35;

    printf("Converted Amount = %.2f", doller);

    return 0;
}


