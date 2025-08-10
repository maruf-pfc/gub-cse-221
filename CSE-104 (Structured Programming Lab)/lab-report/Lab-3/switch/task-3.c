/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 18-7-22
 * problem name			: Take 3 numbers from user. Find the minimum number.
 * problem description	: Take 3 numbers from user. Find the minimum number.
 */
#include<stdio.h>
int main(){
    int a, b, c;
    printf("Enter 3 integer number: ");
    scanf("%d%d%d", &a, &b, &c);

    switch(a < b && a < c){
        case 0:
            switch(b < a && b < c){
                case 0:
                    printf("%d is the smallest number.\n", c);
                    break;
                case 1:
                    printf("%d is the smallest number.\n", b);
                    break;
            }
            break;
        case 1:
            printf("%d is the smallest number.\n", a);
            break;
    }
}