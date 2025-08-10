import java.util.Scanner;

public class MaxValue {
    double Max(double x, double y, double z){
        if(x > y && x > z) return x;
        if(y > x && y > z) return y;
        return z;
    }
    int Max(int x, int y, int z){
        if(x > y && x > z) return x;
        if(y > x && y > z) return y;
        return z;
    }
    int Max(int x, int y){
        if(x > y) return x;
        return y;
    }
    public static void main(String[] args) {
        MaxValue maxValue = new MaxValue();
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter 1st number:");
        double xd = sc.nextDouble();
        System.out.println("Enter 2nd number:");
        double yd = sc.nextDouble();
        System.out.println(maxValue.Max(1, 2, 3));
        System.out.println(maxValue.Max(1, 2));
    }
}