#include <stdio.h>
#include <math.h>
#include <string.h>

char main_Data[100];
char Encoded[100];

int Odd_parity_Hamming(int a, int b, char Encoded[]){
    int count = 0, i, j;
    i = a - 1;
    while (i < b) {
        for (j = i; j < i + a && j < b; j++){
            if (Encoded[j] == '1')  count++;
        }
        i =i+ 2 * a;
    }
    if (count % 2 == 0)  return '0';
    else  return '1';
}

void character_stuffing(char data[], char stuffed[]){
    int i = 0, j = 0;
    while (data[i] != '\0') {
        if (data[i] == 'D' && data[i + 1] == 'L' && data[i + 2] == 'E'){
            stuffed[j++] = 'D';
            stuffed[j++] = 'L';
            stuffed[j++] = 'E';
        }
        stuffed[j++] = data[i++];
    }
    stuffed[j] = '\0';
}

void character_destuffing(char stuffed[], int start, int end, char destuffed[]{
    int i = start, j = 0;
    while (i < end) {
        if (stuffed[i] == 'D' && stuffed[i + 1] == 'L' && stuffed[i + 2] == 'E') i += 3;
        destuffed[j++] = stuffed[i++];
    }
    destuffed[j] = '\0';
}

int main(){
    char encrypted_Data[100], stuffed_Data[200], final_Data[300], destuffed_Data[100];
    int i = 0, G = 0, R = 0, Z, j, k;

    printf("Enter the data to encode using Hamming code (in binary): ");
    scanf("%s", main_Data);

    while (main_Data[G] != '\0') G++;

    while (G > (int)pow(2, i) - (i + 1)){
        R++;
        i++;
    }

    Z = R + G;
    j = k = 0;

    for (i = 0; i < Z; i++){
        if (i == ((int)pow(2, k) - 1)){
            Encoded[i] = '0';
            k++;
        }
        else Encoded[i] = main_Data[j++];
    }
    for (i = 0; i < R; i++) {
        int X = (int)pow(2, i);
        int Y = Odd_parity_Hamming(X, Z, Encoded);
        Encoded[X - 1] = Y;
    }
    Encoded[Z] = '\0';
    printf("Encoded data using Hamming code: %s\n", Encoded);
    printf("Enter the main data to encrypt: ");
    scanf("%s", main_Data);

    for (i = 0; main_Data[i] != '\0'; i++) encrypted_Data[i] = main_Data[i] + 1;
    encrypted_Data[i] = '\0';
    printf("After encryption: %s\n", encrypted_Data);
    
    character_stuffing(encrypted_Data, stuffed_Data);
    printf("After character stuffing: %s\n", stuffed_Data);
    
    strcpy(final_Data, Encoded);
    strcat(final_Data, stuffed_Data);
    
    strcat(final_Data, Encoded);
    printf("Final stuffed data: %s\n", final_Data);
    
    character_destuffing(final_Data, Z, strlen(final_Data) - Z, destuffed_Data);
    printf("After character de-stuffing: %s\n", destuffed_Data);
    
    for (i = 0; destuffed_Data[i] != '\0'; i++) destuffed_Data[i] = destuffed_Data[i] - 1;
    
    printf("After decryption: %s\n", destuffed_Data);
    printf("Decryption completed. Thank you for using our service.\n");
}