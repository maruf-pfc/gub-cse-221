/* Name					: Md. Maruf Sarker
 * Program				: BSC in CSE
 * Section				: 221 D4
 * Instructor			: Ahmed Iqbal Pritom
 * Date					: 18-7-22
 * problem name			: Write a program in C to calculate and print the Electricity bill of a given customer. The unit consumed by the user should be taken from the keyboard and display the total amount to pay to the customer. The charge are as follow :

Unit                               Charge/Unit
-----------------------------------------------
upto 199                            @1.20
200 and above but less than 400     @1.50
400 and above but less than 600     @1.80
600 and above                       @2.00

If bill exceeds 400 then a surcharge of 15% will be charged and the minimum bill should be of Rs. 100/-
Test Data:
800
Expected Output:
Net Amount Paid By the Customer: 1840.00
 */

#include<stdio.h>
int main(){
    int unit;
    float charge,total;

    printf("Enter the unit consumed: ");
    scanf("%d", &unit);

    if(unit <= 199){
        charge = unit * 1.20;
    }
    else if(unit >= 200 && unit < 400){
        charge = unit * 1.50;
    }
    else if(unit >= 400 && unit < 600){
        charge = unit * 1.80;
    }
    else if(unit >= 600){
        charge = unit * 2.00;
    }
    if(unit >= 400){
        total = charge + (charge * 0.15);
    }
    else{
        total = charge;
    }
    printf("Net Amount Paid By the Customer: %.2f\n",total); 


    return 0;
}