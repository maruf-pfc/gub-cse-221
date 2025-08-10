/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 28-6-22
 * problem name			: Write a C Program to enter the amount in dollars and then display the amount by adding 18% as tax. [value=(money + (money * 0.18))]
 * problem description	: Write a C Program to enter the amount in dollars and then display the amount by adding 18% as tax. [value=(money + (money * 0.18))]
 */

#include<stdio.h>
#include<math.h>
#define tax 0.18

int main(){
	double doller, value;

    printf("Enter Your Amount(USD) = ");
    scanf("%lf", &doller);

    value = (doller + (doller * tax));

    printf("Total Amount(with 18%% tax) = %.2lf$\n", value);

    return 0;
}