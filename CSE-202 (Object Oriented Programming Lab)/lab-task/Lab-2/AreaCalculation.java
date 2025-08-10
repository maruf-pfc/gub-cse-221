import java.util.Scanner;

public class AreaCalculation {
    Scanner sc = new Scanner(System.in);

    protected void CalculateTriangleArea(){
        System.out.print("Enter the side1 of triangle: ");
        double a = sc.nextDouble();
        System.out.print("Enter the side2 of triangle: ");
        double b = sc.nextDouble();
        System.out.print("Enter the side3 of triangle: ");
        double c = sc.nextDouble();
        double s = (a + b + c) / 2;
        double area = Math.sqrt(s * (s - a) * (s - b) * (s - c));
        System.out.println("Area of triangle: " + area);
    }

    protected void CalculateRectangleArea(){
        System.out.print("Enter the length of rectangle: ");
        double l = sc.nextDouble();
        System.out.print("Enter the width of rectangle: ");
        double w = sc.nextDouble();
        double area = l * w;
        System.out.println("Area of rectangle: " + area);
    }

    protected void CalculateCircleArea(){
        System.out.print("Enter the radius of circle: ");
        double r = sc.nextDouble();
        double area = Math.PI * r * r;
        System.out.println("Area of circle: " + area);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = 3;
        while(t-- > 0){
            int choice;
            System.out.println("1. Calculate Triangle Area.");
            System.out.println("2. Calculate Rectangle Area.");
            System.out.println("3. Calculate Circle Area.");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            AreaCalculation obj = new AreaCalculation();
            switch(choice){
                case 1:
                    obj.CalculateTriangleArea();
                    break;
                case 2:
                    obj.CalculateRectangleArea();
                    break;
                case 3:
                    obj.CalculateCircleArea();
                    break;
                default:
                    System.out.println("Invalid choice.");
            }
        }
    }
}
/*
1. Calculate Triangle Area.
2. Calculate Rectangle Area.
3. Calculate Circle Area.
Enter your choice: 1
Enter the side1 of triangle: 2 
Enter the side2 of triangle: 3
Enter the side3 of triangle: 4
Area of triangle: 2.9047375096555625
1. Calculate Triangle Area.
2. Calculate Rectangle Area.
3. Calculate Circle Area.
Enter your choice: 2
Enter the length of rectangle: 2
Enter the width of rectangle: 3
Area of rectangle: 6.0
1. Calculate Triangle Area.
2. Calculate Rectangle Area.
3. Calculate Circle Area.
Enter your choice: 3
Enter the radius of circle: 3
Area of circle: 28.274333882308138
*/