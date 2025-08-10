/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 18-7-22
 * problem name			: Write a C program to check whether a triangle is Equilateral,
Isosceles or Scalene.
 * problem description    : 
 Test Data: 50 50 60
Expected Output:
This is an isosceles triangle.
 */

#include<stdio.h>
int main(){
   int side1, side2, side3;

   printf("Enter sides of triangle: ");
   scanf("%d%d%d", &side1, &side2, &side3);

   if(side1 == side2 && side2 == side3) printf("This is an equilateral triangle\n");
   else if(side1 == side2 || side2 == side3 || side3 == side1) printf("This is an isosceles triangle.\n");
   else printf("This is an scalene triangle.\n");
   return 0;
}