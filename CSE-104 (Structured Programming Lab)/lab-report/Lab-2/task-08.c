/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 28-6-22
 * problem name			: Find the roots of a quardratic equation(ax^2 + bx + c = 0)
 * problem description	: Find the roots of a quardratic equation(ax^2 + bx + c = 0)
 */

#include<stdio.h>
#include<math.h>

int main() {

    double a, b, c, discriminant, root1, root2, realPart, imagPart;
    printf("Enter coefficients a, b and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("%.2lf, %.2lf\n", root1, root2);
    }else if (discriminant == 0) {
        root1 = root2 = -b / (2 * a);
        printf("%.2lf, %.2lf\n", root1, root1);
    }else {
        realPart = -b / (2 * a);
        imagPart = sqrt(-discriminant) / (2 * a);
        printf("%.2lf+%.2lfi, %.2f-%.2fi\n", realPart, imagPart, realPart, imagPart);
    }

    return 0;
} 
