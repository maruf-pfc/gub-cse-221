/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 28-6-22
 * problem name			: Take the base and heigh of a triangle and calculate its area.
 * problem description	: Take the base and heigh of a triangle and calculate its area.
 */

#include <stdio.h>

int main()
{
    float base, height;

    printf("Enter base: ");
    scanf("%f", &base);

    printf("Enter height: ");
    scanf("%f", &height);

    printf("Triangle area: %.2f\n", .5 * base * height);

    return 0;
}