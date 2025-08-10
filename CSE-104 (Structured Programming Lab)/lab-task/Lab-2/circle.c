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