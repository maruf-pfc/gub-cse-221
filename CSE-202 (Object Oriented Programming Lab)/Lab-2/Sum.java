public class Sum {
    Sum(int x, int y){
        System.out.println("Sum = " + x + y);
    }
    Sum(int x, int y, int z){
        System.out.println("Sum = " + x + y + z);
    }
    public static void main(String[] args) {
        Sum s1 = new Sum(4, 3);
        Sum s2 = new Sum(24, 32, 43);
    }
}