/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 28-6-22
 * problem name			: Write a C program to enter temperature in Fahrenheit(°F) and convert it into Celsius(°C).
 * problem description	: Write a C program to enter temperature in Fahrenheit(°F) and convert it into Celsius(°C).
 */
#include<stdio.h>
int main() {
    float celsius, fahrenheit;

    printf("Enter the fahrenheit temperature: ");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - 32) * 5 / 9;

    printf("%.2f°F = %.2f°C\n", fahrenheit, celsius);
    
    return 0;
}