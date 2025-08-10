class Shape{
    public void print(){
        System.out.println("This is a shape");
    }
}

class Rectangle extends Shape{
    int length;
    int width;

    Rectangle(int length, int width){
        super();
        this.length = length;
        this.width = width;
    }
    public void print(){

        System.out.println("This is rectangular shape");
        calculateArea();
    }
    public void calculateArea(){
        System.out.println(length * width);
    }
}

class Circle extends Shape{
    int r;

    Circle(int r){
        this.r = r;
    }
    public void print(){
        System.out.println("This is circular shape");
        calculateArea();
    }
    public void calculateArea(){
        System.out.println(3.1416 * r * r);
    }
}

// create a subclass Square of Rectangle having a method to print "Square is a rectangle". Now call the method of "shape" and "rectangle" class by the object of Square class

class Square extends Shape{
    int a;

    Square(int a){
        this.a = a;
    }
    public void print(){
        System.out.println("This is a square");
        calculateArea();
    }
    public void calculateArea(){
        System.out.println(a * a);
    }
}

public class Main {
    public static void main(String[] args) {
        Shape s = new Shape();
        Shape rec = new Rectangle(2, 3);
        Shape cir = new Circle(5);
        Shape sq = new Square(3);

        
        Shape arr [] = {rec, cir, sq};
        for(Shape i : arr){
            i.print();
        }
    }
}