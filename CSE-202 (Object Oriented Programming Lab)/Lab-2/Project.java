import java.util.Scanner;

class Teacher{
    String name;
    String phoneNumber;

    Teacher(String name, String phoneNumber){
        this.name = name;
        this.phoneNumber = phoneNumber;

        display(name, phoneNumber);
    }

    void display(String name, String phoneNumber){
        System.out.println("Teacher Name: " + name + "\nTeacher Phone Number: " + phoneNumber);
    }
}

public class Project {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Teacher[] t = new Teacher[3];

        for(int i = 0; i < 3; i++){
            String name = sc.nextLine();
            String phoneNumber = sc.nextLine();
            t[i] = new Teacher(name, phoneNumber);
        }

        sc.close();
    }
}