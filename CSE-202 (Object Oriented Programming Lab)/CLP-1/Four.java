// Create a class named &#39;Rectangle&#39; with two data members- length and breadth and a
// method to calculate the area which is &#39;length*breadth&#39;. The class has three constructors
// which are :
// 1 - having no parameter - values of both length and breadth are assigned zero.
// 2 - having two numbers as parameters - the two numbers are assigned as length and
// breadth
// respectively.
// 3 - having one number as a parameter - both length and breadth are assigned that
// number.
// Now, create objects of the &#39;Rectangle&#39; class having none, one and two parameters and
// print their areas.

import java.util.*;

class Rectangle{
    int length, breadth;
    
    void area(int length, int breadth){
        System.out.println("Area = " + length * breadth);
    }
    Rectangle(){
        this.length = 0;
        this.breadth = 0;

        area(length, breadth);
    }

    Rectangle(int length, int breadth){
        this.length = length;
        this.breadth = breadth;

        area(length, breadth);
    }

    Rectangle(int n){
        this.length = n;
        this.breadth = n;

        area(length, breadth);
    }
}

public class Four {
    public static void main(String[] args) {
        Rectangle r1 = new Rectangle();
        Rectangle r2 = new Rectangle(3, 4);
        Rectangle r3 = new Rectangle(5);
    }
}