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
    
    printf("Enter year: ");
    scanf("%d", &year);

    switch(((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0)){
        case 0:
            printf("%d is not leap year\n", year); 
            break;
        case 1:
            printf("%d is a leap year\n", year); 
            break;
    }
    return 0;
}