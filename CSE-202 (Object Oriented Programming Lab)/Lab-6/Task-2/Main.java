public class Main {
    public static void main(String[] args) {
        Circle c = new Circle(3);
        c.draw();
        c.area();
        c.perimeter();

        Rectangle r = new Rectangle(2, 4);
        r.draw();
        r.area();
        r.perimeter();
    }
}