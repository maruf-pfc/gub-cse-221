/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 12-7-22
 * problem name			: Write a C program to find sum of first and last digit of any number.
 * problem description	: Write a C program to find sum of first and last digit of any number.
 */

#include <stdio.h>

int main() {
   int num, first, last, sum;

   printf("Enter your number: ");
   scanf("%d", &num);

   // get the last number
   last = num % 10;
   first = num;

   // get the first number deviding it by 10 until num is greater or equal 10
   while(num >= 10){
      num = num / 10;
   }
   first = num;
   sum = first + last;
   printf("Sum of first and last digit is = %d", sum);

   return 0;
}