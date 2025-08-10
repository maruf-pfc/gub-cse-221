import java.util.Scanner;

public class ConstructorOverloading {
    // Take three constructor where first constructor will calculate the area of triangle, second constructor will calcu- late the area of rectangle and third constructor will calculate the area of circle using overloading constructor However, Input must be taken from users.

    double area, side1, side2, side3, radius, length, width;
    // Area of triangle
    ConstructorOverloading(double side1, double side2, double side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
        double s = (side1 + side2 + side3) / 2;
        area = Math.sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    // Area of rectangle
    ConstructorOverloading(double length, double width) {
        this.length = length;
        this.width = width;
        area = length * width;
    }
    // Area of circle
    ConstructorOverloading(double radius) {
        this.radius = radius;
        area = Math.PI * radius * radius;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the side1 of triangle: ");
        double a = sc.nextDouble();
        System.out.print("Enter the side2 of triangle: ");
        double b = sc.nextDouble();
        System.out.print("Enter the side3 of triangle: ");
        double c = sc.nextDouble();
        
        System.out.print("Enter the length of rectangle: ");
        double l = sc.nextDouble();
        System.out.print("Enter the width of rectangle: ");
        double w = sc.nextDouble();

        System.out.print("Enter the radius of circle: ");
        double r = sc.nextDouble();

        ConstructorOverloading obj1 = new ConstructorOverloading(a, b, c);
        ConstructorOverloading obj2 = new ConstructorOverloading(l, w);
        ConstructorOverloading obj3 = new ConstructorOverloading(r);

        System.out.println("Area of triangle: " + obj1.area);
        System.out.println("Area of rectangle: " + obj2.area);
        System.out.println("Area of circle: " + obj3.area);

        sc.close();
    }
}

// Enter the side1 of triangle: 2
// Enter the side2 of triangle: 3
// Enter the side3 of triangle: 4
// Enter the length of rectangle: 2
// Enter the width of rectangle: 3
// Enter the radius of circle: 2
// Area of triangle: 2.9047375096555625
// Area of rectangle: 6.0
// Area of circle: 12.566370614359172