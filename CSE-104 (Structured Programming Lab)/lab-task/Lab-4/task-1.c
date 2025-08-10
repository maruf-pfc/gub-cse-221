#include<stdio.h>
int main(){
    int a, b;
    printf("Enter 2 integer number: ");
    scanf("%d%d", &a, &b);

    switch(a > b){
        case 0:
            printf("%d is the largest number.\n", b);
            break;
        case 1:
            printf("%d is the largest number.\n", a);
            break;
    }
}