// Create a banking application that supports different types of bank accounts, including Savings Account and Current Account. Each account should have the ability to calculate interest based on the account balance. The savings account should calculate interest at a fixed rate of 5% per annum, while the current account should not calculate any interest. Implement the necessary classes and demonstrate polymorphism by calculating interest for both types of accounts.
import java.util.*;

class SavingsAccount{
    private double balance;
    private double interestRate = 0.5;

    public SavingsAccount(double balance){
        this.balance = balance;
    }
    public double getBalance(){
        return balance;
    }
    public void setBalance(double balance){
        this.balance = balance;
    }

    public void display(){
        System.out.println("Balance: " + balance * interestRate);
    }
}

class CurrentAccount{
    private double balance;
    private double interestRate = 0.5;


    public CurrentAccount(double balance){
        this.balance = balance;
    }
    public double getBalance(){
        return balance;
    }
    public void setBalance(double balance){
        this.balance = balance;
    }


    public void display(){
        System.out.println("Balance: " + balance);
    }
}


public class Bank{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Banking Application");
        System.out.println("--------------------");

        System.out.println("Which  type of account do you use? ");
        System.out.println("1. Savings Account");
        System.out.println("2. Current Account");
        System.out.print("Enter account type: ");

        int n;
        n = sc.nextInt();

        if(n == 1){
            SavingsAccount sa = new SavingsAccount(1000);
            sa.display();
        }else{
            CurrentAccount ca = new CurrentAccount(1000);
            ca.display();
        }
    }
}