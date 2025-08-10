public class Rectangle implements Shape{
    double length, width;
    Rectangle(int length, int width){
        this.length = length;
        this.width = width;
    }
    public void draw(){
        System.out.println(name + " Rectangle");
    }
    public void area(){
        System.out.println("Area = " + length * width);
    }
    public void perimeter(){
        System.out.println("Perimeter = " + 2 * (length + width));
    }
}