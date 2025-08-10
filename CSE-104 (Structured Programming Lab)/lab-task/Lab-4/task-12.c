#include<stdio.h>

int main(){
    int a, b, c;

    printf("Enter 3 angles of the triangle: ");
    scanf("%d%d%d", &a, &b, &c);

    switch(a + b + c == 180 && a != 0 && b != 0 && c != 0){
        case 1:
            printf("Valid\n");
            break;
        case 0:
            printf("Invalid\n");
            break;
    }

    return 0;
}