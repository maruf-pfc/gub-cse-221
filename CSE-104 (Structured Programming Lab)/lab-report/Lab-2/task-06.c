/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 28-6-22
 * problem name			: Take an employee's salary as input(int BDT). Convert it into USD.
 * problem description	: Take an employee's salary as input(int BDT). Convert it into USD.
 */


// 1 USD = 91.35BDT
#include <stdio.h>
int main(){
    float taka, doller;

    printf("Enter Your Amount(BDT) = ");
    scanf("%f", &taka);

    doller = taka / 91.35;

    printf("Converted Amount = %.2f$\n", doller);

    return 0;
}
