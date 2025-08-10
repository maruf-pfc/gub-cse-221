public class Arithmetic {
    public static void main(String[] args) {
        try{
            int ans = 100 / 0;
        }catch(ArithmeticException e){
            System.out.println("Exception: " + e);
        }
    }
}