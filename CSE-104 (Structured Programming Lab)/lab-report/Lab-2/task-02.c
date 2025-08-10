/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 28-6-22
 * problem name			: Take the radius of a circle and calculate area and cicumsference.
 * problem description	: Take the radius of a circle and calculate area and cicumsference.
 */

#include <stdio.h>
#define pi 3.1416

int main()
{
    float r, circums;
    
    printf("Enter the radius of the circle: ");
    scanf("%f", &r);

    printf("Circle Area = %.2f\n", pi * r * r);
    printf("Circle Circumference = %.2f\n", 2 * pi * r);

    return 0;
}