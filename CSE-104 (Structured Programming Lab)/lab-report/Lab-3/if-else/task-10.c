/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 18-7-22
 * problem name			: Check if a given year is leap year or not.
 */
#include<stdio.h>
int main(){
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);
    
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
        printf("%d is a leap year\n", year);
    }
    else{
        printf("%d is not a leap year\n", year);
    }
    return 0;
}