import java.util.Scanner;

public class FibonacciNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        int a = 0;
        int b = 1;
        int c = 0;

        for (int i = 0; i < n; i++) {
            System.out.print(c + " ");
            a = b;
            b = c;
            c = a + b;
        }

        System.out.println();
    }
}
