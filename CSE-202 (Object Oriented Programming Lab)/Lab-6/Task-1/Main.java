public class Main {
    public static void main(String[] args) {
        Car car = new Car();
        car.changeGear();
        car.speedUp();
        car.applyBreak();

        Bike bike = new Bike();
        bike.changeGear();
        bike.speedUp();
        bike.applyBreak();

        Bicycle bicycle = new Bicycle();
        bicycle.changeGear();
        bicycle.speedUp();
        bicycle.applyBreak();
    }
}