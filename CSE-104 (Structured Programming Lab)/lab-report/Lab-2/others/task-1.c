/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 28-6-22
 * problem name			: Write a C Program to Calculate Area of a Square, take length of one side as user input.
 * problem description	: Write a C Program to Calculate Area of a Square, take length of one side as user input.
 */
#include<stdio.h>
int main() {
    int side;

    printf("Enter the length of a side: ");
    scanf("%d", &side);

    printf("Area of the square: %d\n", side * side);

    return 0;
}