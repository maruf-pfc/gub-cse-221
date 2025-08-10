#include <stdio.h>

int main()
{
    int a;
    float b;
    char c;
    double d;
    
    printf("Enter an integer number: ");
    scanf("%d",&a);
    printf("You have entered: %d\n", a);
    
    printf("Enter an float number: ");
    scanf("%f",&b);
    printf("You have entered: %.2f\n", b);

    return 0;
}