/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 5-7-22
 * problem name			: Write a C program to check weather a year is leap year or not
 * problem description	: Write a C program to check weather a year is leap year or not
 */

#include <stdio.h>

int main() {
   int year;
   printf("Enter Year = ");
   scanf("%d", &year);

   if (((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0)) printf("%d is a leap year", year);
   else printf("%d is not a leap year", year);

   return 0;
}