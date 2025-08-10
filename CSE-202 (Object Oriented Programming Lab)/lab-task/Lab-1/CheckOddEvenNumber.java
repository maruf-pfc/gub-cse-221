import java.util.ArrayList;
import java.util.Scanner;

public class CheckOddEvenNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        ArrayList<Integer> even = new ArrayList<>();
        ArrayList<Integer> odd = new ArrayList<>();

        for(int i = 1; i <= n; i++)
            if(i % 2 == 0) even.add(i);
            else odd.add(i);
        
        System.out.println("Even numbers: " + even);
        System.out.println("Odd numbers: " + odd);
    }
}
