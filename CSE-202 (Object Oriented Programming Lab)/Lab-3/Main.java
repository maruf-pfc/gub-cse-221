import java.util.Scanner;

class Rectangle{
    int length;
    int width;

    Rectangle(int length, int width){
        this.length = length;
        this.width = width;
    }

    int calcArea(int length, int width){
        return length * width;
    }
}

class Volume extends Rectangle{
    int height;

    Volume(int length, int width, int height){
        super(length, width);
        this.height = height;
    }
    int calcVolume(){
        return length * width * height;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter Length of rectangle: ");
        int length = sc.nextInt();
        System.out.print("Enter Width of rectangle: ");
        int width = sc.nextInt();
        Rectangle r = new Rectangle(length, width);
        System.out.println("Rectangle Area = " + r.calcArea(length, width));

        System.out.print("Enter Height for calculate volume: ");
        int height = sc.nextInt();
        Volume v = new Volume(length, width, height);
        System.out.println("Volume = " + v.calcVolume());

        sc.close();
    }
}
