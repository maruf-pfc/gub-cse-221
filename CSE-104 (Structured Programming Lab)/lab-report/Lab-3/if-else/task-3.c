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
    int n1, n2, n3;
    printf("Enter 3 number: ");
    scanf("%d %d %d", &n1, &n2, &n3);
    if(n1 < n2 && n1 < n3){
        printf("%d is the minimum number\n", n1);
    }
    else if(n2 < n1 && n2 < n3){
        printf("%d is the minimum number\n", n2);
    }
    else{
        printf("%d is the minimum number\n", n3);
    }
    return 0;
}