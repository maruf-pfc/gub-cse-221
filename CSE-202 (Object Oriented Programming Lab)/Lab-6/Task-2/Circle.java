public class Circle implements Shape{
    double r;
    Circle(double r){
        this.r = r;
    }
    public void draw(){
        System.out.println(name + " Circle");
    }
    public void area(){
        System.out.println("Area = " + 3.1416 * r * r);
    }
    public void perimeter(){
        System.out.println("Perimeter = " + 2 * 3.1416 * r);
    }
}