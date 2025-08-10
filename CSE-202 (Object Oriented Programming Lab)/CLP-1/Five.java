// Create a class Vehicle having instance variables speed, and two methods applybreak()
// and speedup(). The constructor of the Vehicle takes an integer value and assigns it to
// speed value. Calling applybreak() will decrease the speed which is applied and
// speedup() will increase the speed. Two classes Bicycle and Car inherit the properties of
// Vehicle and have extra two instance variable name and gear. Their constructor will take
// the name and gear value as input. Design the class and show the status of the vehicle
// name, speed and gear.

import java.util.*;

class Vehicle{
    static int speed;

    Vehicle(int speed){
        this.speed = speed;
    }

    void applyBreak(){
        speed = 0;
    }
    void sppedUp(){
        speed = 50;
    }
}

class Bicycle extends Vehicle{
    String name;
    int gear;

    Bicycle(String name, int gear){
        super(speed);
        this.name = name;
        this.gear = gear;
        print();
    }

    void print(){
        System.out.println("Name = " + name);
        System.out.println("Gear = " + gear);
        System.out.println("Speed = " + speed); 
    }
}

class Car extends Vehicle{
    String name;
    int gear;

    Car(String name, int gear){
        super(speed);
        this.name = name;
        this.gear = gear;
        print();
    }

    void print(){
        System.out.println("Name = " + name);
        System.out.println("Gear = " + gear);
        System.out.println("Speed = " + speed); 
    }
}
public class Five {
    public static void main(String[] args) {
        Vehicle v = new Vehicle(30);
        Bicycle b = new Bicycle("Yamaha", 40);
        Car c = new Car("Lamborghini", 30);
    }
}