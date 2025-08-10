#include<stdio.h>
int main(){
    int age;
    char gen;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("If you are male type 'm' and if you are female type 'f'. ");
    printf("Choose your gender: ");
    scanf(" %c", &gen);

    switch(gen == 'f'){
        case 0:
            switch(age >= 21){
                case 0:
                    printf("You are not eligible for marriage.\n");
                    break;
                case 1:
                    printf("You are eligible for marriage.\n");
                    break;
            }
            break;
        case 1:
            switch(age >= 18){
                case 0:
                    printf("You are not eligible for marriage.\n");
                    break;
                case 1:
                    printf("You are eligible for marriage.\n");
                    break;
            }
            break;
    }
}