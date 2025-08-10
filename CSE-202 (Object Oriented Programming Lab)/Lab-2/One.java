class Student{
    int id;
    String name;
    String location;
}

public class One{
    public static void main(String[] args){
        Student s1 = new Student();
        s1.id = 221002063;
        s1.name = "Md. Maruf Sarker";
        s1.location = "Rampura Dhaka";

        System.out.println(s1.id);
        System.out.println(s1.name);
        System.out.println(s1.location);

        System.out.println("ID: " + s1.id + "\nName: " + s1.name + "\nLocation: " + s1.location);
    }
}