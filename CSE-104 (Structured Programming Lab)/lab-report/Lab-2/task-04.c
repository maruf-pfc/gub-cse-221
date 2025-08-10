/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 28-6-22
 * problem name			: Write a C program to enter temperature in °Celsius and convert it into °Fahrenheit.
 * problem description	: Take today's temperature(in degree celsius) from user. Convert it into fahrenheit.
 */
#include<stdio.h>
int main() {
    float celsius, fahrenheit;

    printf("Enter the celsius temperature: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9 / 5) + 32;

    printf("%.2f°C = %.2f°F\n", celsius, fahrenheit);

    return 0;
}