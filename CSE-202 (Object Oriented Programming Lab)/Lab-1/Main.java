import java.util.*;

// Written by: Md. Maruf Sarker
// Platform: 
// Problem: 
// Language: java
// Date: 2023-02-28
// Difficulty Rating: 

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // int hungry;
        // int 2AB;
        // int 312.2;
        // int MOBILE;
        // int "Ans";
        // int $30;
        // int Yes/No;
        // int student-id;
        // int A + 3;
        // int 'X';
        // int return;

        System.out.println("Question 1");
        String firstName = "Maruf";
        String lastName = "Sarker";
        System.out.println(firstName + lastName);


        System.out.println("Question 2-3");
        // take student id from user
        System.out.print("Enter your student ID: ");
        int studentID = sc.nextInt();
        System.out.println("Your Student ID is: " + studentID);

        System.out.println("Question 4");
        // take student name from user
        System.out.print("Enter your name: ");
        String str = sc.next();
        System.out.println("Hello, " + str);


        System.out.println("Question 5");
        System.out.print("Enter two integer variables: ");
        int a = sc.nextInt();
        int b = sc.nextInt();
        int sum1 = a + b;
        int sub = a - b;
        int prod = a * b;
        System.out.println("Sum of a + b = " + sum1);
        System.out.println("Sub of a - b = " + sub);
        System.out.println("Prod of a * b =" + prod);


        System.out.println("Question 6");
        System.out.print("Enter two floating variables: ");
        float c = sc.nextFloat();
        float d = sc.nextFloat();
        float sum2  = c + d;
        System.out.println("Sum of a + b = " + sum2);

        
        System.out.println("Question 7");
        System.out.println("Enter radius: ");
        float r = sc.nextFloat();
        System.out.print("Circle Area: ");
        System.out.println(3.1416 * r * r);


        System.out.println("Question 8");
        System.out.print("Enter two integer value: ");
        int x = sc.nextInt();
        int y = sc.nextInt();

        if(x > y) System.out.println("first");
        else System.out.println("second");


        System.out.println("Question 9");
        System.out.print("Enter two integer value: ");
        int p = sc.nextInt();
        int q = sc.nextInt();

        if(p > q) System.out.println("first is greater");
        else System.out.println("first is not greater");


        System.out.println("Question 10");
        System.out.print("Enter two integer value: ");
        int m = sc.nextInt();
        int n = sc.nextInt();

        if(m > n) System.out.println("first is greater");
        else if(m < n) System.out.println("second is greater");
        else System.out.println("the numbers are equal");


        System.out.println("Question 11");
        System.out.print("Enter two integer value: ");
        int o = sc.nextInt();
        int oo = sc.nextInt();

        if(o > oo) System.out.println(o - oo);
        else if(o < oo) System.out.println(p - oo);


        System.out.println("Question 12");
        System.out.print("Enter a integer value: ");
        int num = sc.nextInt();
        String ans = (num % 2 == 0) ? "even" : "odd";
        System.out.println(ans);



        System.out.println("Question 13, 14");
        System.out.print("Enter a integer value: ");
        int nn = sc.nextInt();

        if(nn % 2 == 0 || nn % 5 == 0)System.out.println("Multiple of 2 or 5");
        else System.out.println("Not multiple of 2 or 5");


        System.out.println("Question 14");
        System.out.print("Enter a string: ");

        String str1 = sc.next();
        System.out.println(str1.length());


        System.out.println("Question 15");
        System.out.println("Enter a string: ");
        String str2 = sc.next();
        for(int i = 0; i < str2.length(); i++)
            System.out.println(str2.charAt(i));


        System.out.println("Question 16");
        System.out.println("Enter 8 int between 2 and 4");

        int two = 0;
        int three = 0;
        int four = 0;

        ArrayList<Integer> list = new ArrayList<Integer>();
        for(int i = 0; i < 8; i++){
            int in = sc.nextInt();
            list.add(in);
            if(in == 2) two++;
            if(in == 3) three++;
            if(in == 4) four++;
        }

        System.out.println("Two = " + two);
        System.out.println("Three = " + three);
        System.out.println("Four = " + four);



        System.out.println("Question 18");
        // Type Casting... 
        // double/int/char/boolean to String
        // String to double/int/char/boolean


        System.out.println("Question 19");
        // prime number
        ArrayList<Integer> list1 = new ArrayList<Integer>();
        System.out.print("Enter the limit: ");
        int nnn = sc.nextInt();



        System.out.print("Question 20");
        /*
         * 1
         * 2 2
         * 3 3 3 
         * 4 4 4 4 
         * 5 5 5 5 5
         */

        System.out.print("Enter a number");
        int numm = sc.nextInt();

        for(int i = 1; i <= numm; i++){
            for(int j = 1; j <= i; j++){
                System.out.print(i + " ");
            }
            System.out.println();
        }

        sc.close();
    }
}