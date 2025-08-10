/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 18-7-22
 * problem name			: Take an integer number from user. Print if the number is even-
positive/ odd-positive / even-negative / odd-negative
 */

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