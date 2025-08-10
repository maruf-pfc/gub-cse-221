/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 18-7-22
 * problem name			: Write a C program to check whether a triangle is Equilateral, Isosceles or Scalene.
 * Test Data: 50 50 60
Expected Output: This is an isosceles triangle.
 */

#include<stdio.h>

int main(){
    int a, b, c;

    printf("Enter 3 angles of the triangle: ");
    scanf("%d%d%d", &a, &b, &c);

    switch(a == b && b == c){
        case 1:
            printf("This is an Equilateral triangle.\n");
            break;
        case 0:
            switch(a == b || b == c || a == c){
                case 1:
                    printf("This is an Isosceles triangle.\n");
                    break;
                case 0:
                    printf("This is a Scalene triangle.\n");
                    break;
            }
            break;
    }

    return 0;
}