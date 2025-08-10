/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 28-6-22
 * problem name			: Find the linear distance between two points in a cartesian coordinate system.
 * problem description	: Find the linear distance between two points in a cartesian coordinate system.
 */

#include<stdio.h>
#include<math.h>

int main(){
	double x1, x2, y1, y2, distance, p, q;
	
	printf("Enter the value of x1 and y1: ");
	scanf("%lf%lf", &x1, &y1);
	printf("Enter the value of x2 and y2: ");
	scanf("%lf%lf", &x2, &y2);
	
	p = (x2 - x1) * (x2 - x1);
	q = (y2 - y1) * (y2 - y1);
	
	distance = sqrt(p + q);
	
	printf("Distance between two points = %.4lf\n", distance);
	
	return 0;
}