import java.util.*;
 
public class Two{   
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
         
        int n, i, count, digit, temp;
        System.out.print("Enter any number: ");
        n = sc.nextInt();
        System.out.println("Digit Frequency");
        for(i = 0;i <= 9; i++){
            count = 0;
            temp = n;
            while(temp > 0){
                digit = temp % 10;
                if(digit == i) count++;
                temp = temp / 10;
            }
            if(count > 0) System.out.println(i + "\t" + count);
        }
         
        sc.close();
    }
}