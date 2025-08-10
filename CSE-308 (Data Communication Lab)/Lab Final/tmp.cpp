#include <stdio.h>

int main() {
    char data[4];
    int count = 0, H,L;
     H = 0;
     L = 0;
    printf("Enter four bits : ");
    for (int i = 0; i < 4; i++) {
        scanf("%c", &data[i]);
        if (data[i] == 'H') {
        count++;
        }
    }

    printf(count % 2 == 0 ? "Parity bit is Even\n" : "Parity bit is Odd\n");
}