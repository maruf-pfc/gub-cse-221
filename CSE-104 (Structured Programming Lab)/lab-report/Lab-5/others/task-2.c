/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 19-7-22
 * problem name			: Print Fibonacci series until a given number. For instance, if a user wants to print Fibonacci series until
1000, print all the Fibonacci number below 1000.
 * problem description	: Print Fibonacci series until a given number. For instance, if a user wants to print Fibonacci series until
1000, print all the Fibonacci number below 1000.
 */

#include <stdio.h>
int main() {

    int i, n;
    int t1 = 0, t2 = 1;
    int next = t1 + t2;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: %d, %d, ", t1, t2);

    for (i = 3; i <= n; ++i) {
        printf("%d, ", next);
        t1 = t2;
        t2 = next;
        next = t1 + t2;
    }

    return 0;
}
