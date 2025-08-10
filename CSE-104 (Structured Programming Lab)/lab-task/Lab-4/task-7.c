#include<stdio.h>

int main(){
    int n;

    printf("Enter an integer number: ");
    scanf("%d", &n);

    switch(n > 0){
        case 0:
            switch(n % 2 == 0){
                case 0:
                    printf("Odd Negative\n");
                    break;
                case 1:
                    printf("Even Negative\n");
                    break;
            }
            break;
        case 1:
            switch(n % 2 == 0){
                case 0:
                    printf("Odd Positive\n");
                    break;
                case 1:
                    printf("Even Positive\n");
                    break;
            }
            break;
    }
    return 0;
}