import java.util.Scanner;

public class Input {
    public int n, n1, n2;

    Scanner sc = new Scanner(System.in);

    public void input1() {
        System.out.print("Enter a number: ");
        n = sc.nextInt();
    }

    public void input2() {
        System.out.print("Enter first number: ");
        n1 = sc.nextInt();
        System.out.print("Enter second number: ");
        n2 = sc.nextInt();
    }

    public int add(int n1, int n2) {
        return n1 + n2;
    }

    public int sub(int n1, int n2) {
        return n1 - n2;
    }

    public int mul(int n1, int n2) {
        return n1 * n2;
    }

    public int div(int n1, int n2) {
        return n1 / n2;
    }

    public int mod(int n1, int n2) {
        return n1 % n2;
    }

    public int fact(int n) {
        int f = 1;
        for (int i = 1; i <= n; i++) {
            f *= i;
        }
        return f;
    }

    public int sqr(int n) {
        return n * n;
    }

    public int cube(int n) {
        return n * n * n;
    }

    public int pow(int n, int p) {
        int pw = 1;
        for (int i = 1; i <= p; i++) {
            pw *= n;
        }
        return pw;
    }

    public int gcd(int n1, int n2) {
        int gcd = 1;
        for (int i = 1; i <= n1 && i <= n2; i++) {
            if (n1 % i == 0 && n2 % i == 0) {
                gcd = i;
            }
        }
        return gcd;
    }

    public int lcm(int n1, int n2) {
        int lcm = 1;
        for (int i = 1; i <= n1 && i <= n2; i++) {
            if (n1 % i == 0 && n2 % i == 0) {
                lcm = (n1 * n2) / i;
            }
        }
        return lcm;
    }
}
