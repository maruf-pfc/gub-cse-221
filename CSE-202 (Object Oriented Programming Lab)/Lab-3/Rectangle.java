/*
 * Write a program which has one class called Rectangle which has two private variables height and width and four functions get_height, get_width and set_value and area.
 * print the area in main function
 */

public class Rectangle {
    private int height = 3;
    private int width = 2;

    int get_height() {
        return height;
    }

    int get_width() {
        return width;
    }

    void set_value(int height, int width) {
        this.height = height;
        this.width = width;
    }

    private int area() {
        return height * width;
    }
        
    public static void main(String[] args) {
        Rectangle r = new Rectangle();
        System.out.println(r.area());
    }
}
