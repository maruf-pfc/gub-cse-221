import java.util.Scanner;

// x^2/1! + x^4/3! + x^6/5! + x^8/7! + x^10/9! + ... + x^n/(n-1)!

public class FactorialSumOddSeries {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        System.out.print("Enter x: ");
        int x = sc.nextInt();

        int sum = 0;

        for (int i = 1; i <= n; i += 2) {
            int fact = 1;
            int pow = 1;

            for (int j = 1; j <= i; j++) {
                fact *= j;
            }

            for (int j = 1; j <= i; j++) {
                pow *= x;
            }

            sum += pow / fact;
        }

        System.out.println("Sum of factorials: " + sum);
    }
}
