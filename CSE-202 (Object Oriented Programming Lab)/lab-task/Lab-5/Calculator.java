import java.util.Scanner;

public class Calculator extends Input{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int choice;
        do{
            System.out.println("Thanks for using this calculator.");
            System.out.println("Please enter the operation you want to perform.");
            System.out.println("1. Addition");
            System.out.println("2. Subtraction");
            System.out.println("3. Multiplication");
            System.out.println("4. Division");
            System.out.println("5. Modulus");
            System.out.println("6. Factorial");
            System.out.println("7. Square");
            System.out.println("8. Cube");
            System.out.println("9. Power");
            System.out.println("10. GCD");
            System.out.println("11. LCM");
            System.out.println("12. Exit");

            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            Input obj = new Input();

            switch(choice){
                case 1:
                    obj.input2();
                    System.out.println(obj.n1 + " + " + obj.n2 + " = " + obj.add(obj.n1, obj.n2));
                    break;
                case 2:
                    obj.input2();
                    System.out.println(obj.n1 + " - " + obj.n2 + " = " + obj.sub(obj.n1, obj.n2));
                    break;
                case 3:
                    obj.input2();
                    System.out.println(obj.n1 + " * " + obj.n2 + " = " + obj.mul(obj.n1, obj.n2));
                    break;
                case 4:
                    obj.input2();
                    System.out.println(obj.n1 + " / " + obj.n2 + " = " + (double)obj.div(obj.n1, obj.n2));
                    break;
                case 5:
                    obj.input2();
                    System.out.println(obj.n1 + " % " + obj.n2 + " = " + obj.mod(obj.n1, obj.n2));
                    break;
                case 6:
                    obj.input1();
                    System.out.println("The factorial of " + obj.n + "! is = " + obj.fact(obj.n));
                    break;
                case 7:
                    obj.input1();
                    System.out.println("The square of " + obj.n + " is = " + obj.sqr(obj.n));
                    break;
                case 8:
                    obj.input1();
                    System.out.println("The cube of " + obj.n + " is = " + obj.cube(obj.n));
                    break;
                case 9:
                    obj.input2();
                    System.out.println("The power of " + obj.n1 + "^" + obj.n2 + " = " + obj.pow(obj.n1, obj.n2));
                    break;
                case 10:
                    obj.input2();
                    System.out.println("The GCD of (" + obj.n1 + "," + obj.n2 + ") = " + obj.gcd(obj.n1, obj.n2));
                    break;
                case 11:
                    obj.input2();
                    System.out.println("The LCM of (" + obj.n1 + "," + obj.n2 + ") = " + obj.lcm(obj.n1, obj.n2));
                    break;
                case 12:
                    System.out.println("Thank you for using this calculator.");
                    System.exit(0);
            }
        }while(choice != 12);
    }
}
