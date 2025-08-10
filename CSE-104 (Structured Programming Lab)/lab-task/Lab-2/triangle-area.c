#include <stdio.h>

int main()
{
    float base, height;

    printf("Enter base: ");
    scanf("%f", &base);

    printf("Enter height: ");
    scanf("%f", &height);

    printf("Triangle area: %.2f", .5 * base * height);

    return 0;
}