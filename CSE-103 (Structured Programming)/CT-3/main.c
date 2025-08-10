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
            // printf("%c", '#');
            ch = '#';
        }else if(digit == 2){
            // printf("%c", 'a');
            ch = 'a';
        }else if(digit == 3){
            // printf("%c", 't');
            ch = 't';
        }else if(digit == 4){
            // printf("%c", 'j');
            ch = 'j';
        }else if(digit == 5){
            // printf("%c", '9');
            ch = '9';
        }else if(digit == 6){
            // printf("%c", 'E');
            ch = 'E';
        }else if(digit == 7){
            // printf("%c", '@');
            ch = '@';
        }else if(digit == 8){
            // printf("%c", '2');
            ch = '2';
        }else if(digit == 9){
            // printf("%c", 'F');
            ch = 'F';
        }else if(digit == 0){
            // printf("%c", '?');
            ch = '?';
        }
        i++;
        password_generator(ch);
    }
}

void Input_Number(char str){
    int x = 0;
    for(x; str != '\0'; x++);

    if(x != 5){
        printf("Wrong input\n");
    }else{
        character_extractor(str);
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
