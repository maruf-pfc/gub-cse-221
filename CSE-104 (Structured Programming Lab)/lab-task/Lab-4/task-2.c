#include<stdio.h>
int main(){
    int n;
    printf("Enter an integer number: ");
    scanf("%d", &n);

    switch(n >= 0){
        case 0:
            printf("%d is a negative number.\n", n);
            break;
        case 1:
            switch(n == 0){
                case 0:
                    printf("%d is a positive number.\n", n);
                    break;
                case 1:
                    printf("%d is zero.\n", n);
                    break;
            }
            break;
        default:
            printf("Wrong Input\n");
            break;
    }
}
