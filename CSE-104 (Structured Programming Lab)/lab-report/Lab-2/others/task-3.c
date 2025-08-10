/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 28-6-22
 * problem name			: Write a C program to enter marks of five subjects and calculate total and average marks.
 * problem description	: Write a C program to enter marks of five subjects and calculate total and average marks.
 */
#include<stdio.h>
int main() {
    float mat, cse, phy, che, eap;
    float total, average;

    printf("Enter marks of five subjects: ");
    scanf("%f%f%f%f%f", &mat, &cse, &phy, &che, &eap);

    total = mat + cse + phy + che + eap;
    average = total / 5.0;

    printf("Total marks = %.2f\n", total);
    printf("Average marks = %.2f\n", average);
    
    return 0;
}