class Car{
    String brand;

    Car(){
        this.brand = "Ford";
    }

    public void getBrand(){
        System.out.println("Brand: " + brand);
    }
}

public class Main {
    public static void main(String[] args) {
        Car c = new Car();
        c.getBrand();
    }
}