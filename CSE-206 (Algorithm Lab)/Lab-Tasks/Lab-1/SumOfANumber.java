class SumOfANumber{
    public static void main(String[] args){
        int num = 54321;
        int sum = 0;

        for(int i = 0; i < 5; i++){
            sum += num % 10;
            num /= 10;
        }

        System.out.println(sum);
    }
}