/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 28-6-22
 * problem name			: Write a C program to convert a given integer (in seconds) to hours, minutes and seconds. 
 * problem description	: Write a C program to convert a given integer (in seconds) to hours, minutes and seconds. 
 */

#include <stdio.h>
int main() {
	int sec, h, m, s;
    
	printf("Input seconds: ");
	scanf("%d", &sec);
	
	h = (sec/3600); 
	m = (sec -(3600*h))/60;
	s = (sec -(3600*h)-(m*60));
	
	printf("H:M:S - %d:%d:%d\n",h,m,s);
	
	return 0;
}