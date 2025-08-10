class Inheritance{
    protected String name;
    String location;
    String contact;

    Inheritance(String name, String location, String contact){
        this.name = name;
        this.location = location;
        this.contact = contact;
    }

    void display(){
        System.out.println(name + " " + location + " " + contact);
    }
}

class Student{
    static int count = 0;

    Student(){
        count++;
    }
}

public class Teacher extends Inheritance{
    static String versity = "GUB";
    String dept;

    public String getName(){
        return name;
    }
    public void setName(String name){
        this.name = name;
    }

    @Override
    void display(){
        System.out.println(name + " " + location + " " + contact + " " + versity + " " + dept);
    }

    // Teacher(String name, String location, String contact, String versity, String dept){
    //     super(name, location, contact);
    //     // child class theke parent class er constructor k call korar jonno amra super use kori
    //     // this.versity = versity;
    //     this.dept = dept;
    // }
    Teacher(String name, String location, String contact, String dept){
        super(name, location, contact);
        // child class theke parent class er constructor k call korar jonno amra super use kori
        // this.versity = versity;
        this.dept = dept;
    }
    public static void main(String[] args) {
        // Teacher t1 = new Teacher();
        // t1.name = "Maruf Sarker";
        // t1.location = "Mirpur";
        // t1.contact = "732074203742";
        // t1.versity = "GUB";
        // t1.dept = "CSE";

        // t1.displayTeacher();


        // Teacher t = new Teacher("Maruf Sarker", "Rampura, Dhaka", "01843579712", "Green University Of Bangladesh", "CSE");
        Teacher t = new Teacher("Maruf Sarker", "Rampura, Dhaka", "01843579712", "CSE");
        t.display();




        Student s1 = new Student();
        System.out.println(Student.count);
        Student s2 = new Student();
        System.out.println(Student.count);
        Student s3 = new Student();
        System.out.println(Student.count);
    }
}
