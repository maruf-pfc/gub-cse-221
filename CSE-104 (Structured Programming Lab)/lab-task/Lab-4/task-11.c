#include<stdio.h>

int main(){
    int a, b, c;

    printf("Enter 3 sides of the triangle: ");
    scanf("%d%d%d", &a, &b, &c);

    switch(a + b <= c || a + c <= b || b + c <= a){
        case 1:
            printf("Invalid\n");
            break;
        case 0:
            printf("Valid\n");
            break;
    }

    return 0;
}