import java.util.Scanner;

public class FactorialSumOddNumbers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        int sum = 0;

        for (int i = 1; i <= n; i += 2) {
            int fact = 1;
            for (int j = 1; j <= i; j++) {
                fact *= j;
            }
            sum += fact;
        }

        System.out.println("Sum of factorials: " + sum);
    }
}
