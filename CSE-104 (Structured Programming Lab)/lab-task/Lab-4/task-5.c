#include<stdio.h>
int main(){
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);

    switch(age >= 18){
        case 0:
            printf("You are not eligible for voting.\n");
            break;
        case 1:
            printf("You are eligible for voting.\n");
            break;
    }
}