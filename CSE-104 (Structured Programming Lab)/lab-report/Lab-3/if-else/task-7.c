/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 18-7-22
 * problem name			: Take an integer number from user. Print if the number is even-
positive/ odd-positive / even-negative / odd-negative?
 */
#include<stdio.h>
int main(){
    int n;
    
    printf("Enter an integer number: ");
    scanf("%d", &n);

    if(n > 0){
        if(n % 2 == 0) printf("Even Positive\n");
        else printf("Odd Positive\n");
    }else{
        if(n % 2 == 0) printf("Even Negative\n");
        else printf("Odd Negative\n");
    }

    return 0;
}