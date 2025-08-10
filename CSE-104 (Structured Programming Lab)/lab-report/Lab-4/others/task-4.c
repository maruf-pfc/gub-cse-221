/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 12-7-22
 * problem name			: Write a program in C to find the sum of the series 1 +11 + 111 + 1111 + .. n terms.
 * problem description	: Write a program in C to find the sum of the series 1 +11 + 111 + 1111 + .. n terms.
 */

#include <stdio.h>

int main(){
   int n, i; 
   long sum = 0;
   long int temp = 1;

   printf("Input the number of terms : ");
   scanf("%d", &n);

   for(i = 1;i <= n; i++)
   {
      printf("%ld  ",temp);
      if(i < n) printf("+ ");
      sum = sum + temp;
      temp = (temp * 10) + 1;
   }
   printf("The Sum is : %ld\n",sum);

   return 0;
}