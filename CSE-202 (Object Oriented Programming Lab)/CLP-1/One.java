// Write a Java program to input basic salary of an employee and calculate its Gross salary
// according to following:
// Basic Salary &lt;= 10000: HRA = 20%, DA = 80%
// Basic Salary &lt;= 20000: HRA = 25%, DA = 90%
// Basic Salary &gt; 20000: HRA = 30%, DA = 95%

import java.util.*;

public class One {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter your salary: ");
        double salary = sc.nextDouble();
        double hra, da;

        if(salary <= 10000) {
            hra = .2;
            da = .8;
            salary *= (hra + da);
            System.out.println("Salary =" + salary);
        }else if(salary <= 20000) {
            hra = .25;
            da = .9;
            salary *= (hra + da);
            System.out.println("Salary =" + salary);
        }else if(salary > 20000) {
            hra = .3;
            da = .95;
            salary *= (hra + da);
            System.out.println("Salary = " + salary);
        }
        sc.close();
    }
}