public class ArrayIndexOutOfBounds {
    public static void main(String[] args) {
        try{
            int a[] = new int[5];  
            a[10] = 50; 
        }catch(NumberFormatException e){
            System.out.println("Exception " + e);
        }
    }
}