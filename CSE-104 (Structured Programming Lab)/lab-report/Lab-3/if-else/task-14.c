/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 18-7-22
 * problem name			: Write a C program to accept a coordinate point in a XY coordinate
system and determine in which quadrant the coordinate point lies.
 * problem description    : Test Data: 7 9
Expected Output:
The coordinate point (7, 9) lies in the First quadrant.
 */
#include<stdio.h>
int main(){
    int x, y;
    
    printf("Enter a coordinate point in a XY coordinate system: ");
    scanf("%d%d", &x, &y);
    
    if(x > 0 && y > 0) printf("The coordinate point (%d, %d) lies in the First quadrant.\n", x, y);
    else if(x < 0 && y > 0) printf("The coordinate point (%d, %d) lies in the Second quadrant.\n", x, y);
    else if(x < 0 && y < 0) printf("The coordinate point (%d, %d) lies in the Third quadrant.\n", x, y);
    else if(x > 0 && y < 0) printf("The coordinate point (%d, %d) lies in the Fourth quadrant.\n", x, y);
    else if(x == 0 && y == 0) printf("Origin\n", x, y);
    else printf("Wrong Input\n");

    return 0;
}