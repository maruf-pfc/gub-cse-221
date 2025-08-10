/*
 * Green University of Bangladesh
 * Department of Computer Science and Engineering
 * CSE-201 (Object Oriented Programming)
 * Name     : Md. Maruf Sarker
 * ID       : 221002063
 * Section  : D4
 * Email    : marufsarkercse2022@gmail.com
 */

import java.util.*;

public class Basics{
    static Scanner sc = new Scanner(System.in);
    static void largeAndSmallNumber(){
        System.out.println("Large and Small Number Calculate");
        System.out.print("Enter three numbers: ");
        int x = sc.nextInt();
        int y = sc.nextInt();
        int z = sc.nextInt();

        int large = (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z);
        System.out.println("Largest number: " + large);
        int small = (x < y) ? ((x < z) ? x : z) : ((y < z) ? y : z);
        System.out.println("Smallest number: " + small);
    }
    static void leapYear(){
        System.out.println("Leap Year Calculate");
        System.out.print("Enter the year: ");
        int year = sc.nextInt();

        if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) System.out.println("Leap Year");
        else System.out.println("Not a Leap Year");
    }
    static void primeNumber(){
        System.out.println("Prime Number Calculate");
        System.out.print("Enter the number: ");
        int num = sc.nextInt();
        int count = 0;

        for(int i = 1; i <= num; i++) if(num % i == 0) count++;
        if(count == 2) System.out.println("Prime Number");
        else System.out.println("Not a Prime Number");
    }
    static void factorial(){
        System.out.println("Factorial Calculate");
        System.out.print("Enter the number: ");
        int num = sc.nextInt();
        int fact = 1;

        for(int i = 1; i <= num; i++) fact *= i;
        System.out.println(fact);
    }
    static void fibonacci(){
        System.out.println("Fibonacci Series");
        System.out.print("Enter the number of terms: ");
        int num = sc.nextInt();
        int a = 0, b = 1, c = 0;

        for(int i = 1; i <= num; i++){
            System.out.print(a + " ");
            c = a + b;
            a = b;
            b = c;
        }
    }
    static void armstrong(){
        System.out.println("Armstrong Number");
        System.out.print("Enter the number: ");
        int num = sc.nextInt();
        int temp = num;
        int sum = 0;

        while(temp != 0){
            int rem = temp % 10;
            sum += rem * rem * rem;
            temp /= 10;
        }
        if(sum == num) System.out.println("Armstrong Number");
        else System.out.println("Not an Armstrong Number");
    }
    static void palindrome(){
        System.out.println("Palindrome Number");
        System.out.print("Enter the number: ");
        int num = sc.nextInt();
        int temp = num;
        int rev = 0;

        while(temp != 0){
            int rem = temp % 10;
            rev = rev * 10 + rem;
            temp /= 10;
        }
        if(rev == num) System.out.println("Palindrome Number");
        else System.out.println("Not a Palindrome Number");
    }
    static void reverseNumber(){
        System.out.println("Reverse Number");
        System.out.print("Enter the number: ");
        int num = sc.nextInt();
        int temp = num;
        int rev = 0;

        while(temp != 0){
            int rem = temp % 10;
            rev = rev * 10 + rem;
            temp /= 10;
        }
        System.out.println(rev);
    }
    static void sumOfDigits(){
        System.out.println("Sum of Digits");
        System.out.print("Enter the number: ");
        int num = sc.nextInt();
        int temp = num;
        int sum = 0;

        while(temp != 0){
            int rem = temp % 10;
            sum += rem;
            temp /= 10;
        }
        System.out.println(sum);
    }
    static void binarySearch(){
        System.out.println("Binary Search");
        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];

        System.out.println("Enter the elements of the array: ");
        for(int i = 0; i < n; i++) arr[i] = sc.nextInt();

        // sorting the array in ascending order using bubble sort
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - i - 1; j++){
                if(arr[j] > arr[j + 1]){
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        System.out.println("Enter the element to be searched: ");
        int key = sc.nextInt();

        int low = 0, high = n - 1, mid = 0;
        boolean flag = false;

        while(low <= high){
            mid = (low + high) / 2;
            if(arr[mid] == key){
                flag = true;
                break;
            }
            else if(arr[mid] < key) low = mid + 1;
            else high = mid - 1;
        }
        if(flag) System.out.println("Element found at index: " + mid);
        else System.out.println("Element not found");
    }
    static void menu(){
        System.out.println("1. Large and Small Number");
        System.out.println("2. Leap Year");
        System.out.println("3. Prime Number");
        System.out.println("4. Factorial");
        System.out.println("5. Fibonacci Series");
        System.out.println("6. Armstrong Number");
        System.out.println("7. Palindrome Number");
        System.out.println("8. Reverse Number");
        System.out.println("9. Sum of Digits");
        System.out.println("10. Binary Search");
        System.out.println("11. Exit");
    }
    public static void main(String[] args) {
        int choice;
        do{
            System.out.println("\n\nJava Basic Programs");
            menu();
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch(choice){
                case 1:
                    System.out.print("\033[H\033[2J");
                    largeAndSmallNumber();
                    break;
                case 2:
                    System.out.print("\033[H\033[2J");
                    leapYear();
                    break;
                case 3:
                    System.out.print("\033[H\033[2J");
                    primeNumber();
                    break;
                case 4:
                    System.out.print("\033[H\033[2J");
                    factorial();
                    break;
                case 5:
                    System.out.print("\033[H\033[2J");
                    fibonacci();
                    break;
                case 6:
                    System.out.print("\033[H\033[2J");
                    armstrong();
                    break;
                case 7:
                    System.out.print("\033[H\033[2J");
                    palindrome();
                    break;
                case 8:
                    System.out.print("\033[H\033[2J");
                    reverseNumber();
                    break;
                case 9:
                    System.out.print("\033[H\033[2J");
                    sumOfDigits();
                    break;
                case 10:
                    System.out.print("\033[H\033[2J");
                    binarySearch();
                    break;
                case 11:
                    System.out.print("\033[H\033[2J");
                    System.out.println("Thank you for using the program\n");
                    break;
            }
        }while(choice != 11);
    }
}