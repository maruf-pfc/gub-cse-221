public class StringIndexOutOfBounds {
    public static void main(String[] args) {
        try{
            String s = "abc";
            System.out.println(s.charAt(10));
        }catch(StringIndexOutOfBoundsException e){
            System.out.println("Exception " + e);
        }
    }
}