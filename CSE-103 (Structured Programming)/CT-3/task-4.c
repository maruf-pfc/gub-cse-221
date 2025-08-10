// Cyber Security is a key issue to protect our daily documents and applications stored and submitted in various platforms. Having a robust encryption system to our generated password is very essential in this perspective. Your task is to create a nice and smooth encrypted password generator. Follow the instructions carefully to build the password generator.

#include <stdio.h>
void password_generator(char ch){
    printf("%c", ch);
}
void character_extractor(int n){
    int temp = n;
    int i = 0;
    char ch;
    while(temp != 0){
        int digit = temp % 10;
        temp /= 10;
        if(digit == 1){
            ch = '#';
        }else if(digit == 2){
            ch = 'a';
        }else if(digit == 3){
            ch = 't';
        }else if(digit == 4){
            ch = 'j';
        }else if(digit == 5){
            ch = '9';
        }else if(digit == 6){
            ch = 'E';
        }else if(digit == 7){
            ch = '@';
        }else if(digit == 8){
            ch = '2';
        }else if(digit == 9){
            ch = 'F';
        }else if(digit == 0){
            ch = '?';
        }
        i++;
        password_generator(ch);
    }
}
void Input_Number(int n){
    // length of the number
    int len = 0;
    int temp = n;
    while(temp != 0){
        temp /= 10;
        len++;
    }
    if(len != 5){
        printf("Wrong input\n");
    }else{
        character_extractor(n);
    }
}
int main(){
    int n;
    printf("Enter a 5 digit number: ");
    scanf("%d", &n);
    Input_Number(n);
    printf("\n");
    return 0;
}