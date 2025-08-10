// Written by: Md. Maruf Sarker
// Platform: Linux
// Problem: Student Management System
// Language: cpp
// Date: 2022-11-27
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int i = 0, n = 40;
// add student record using array
struct student{
   int id; string name; string dept; string session; string email; string phone;
} s[40];
void add_student_record(){
   system("clear");
   // add student record using array insertion
   cout << "Enter last three digit of student id: "; cin >> s[i].id; fflush(stdin);
   cout << "Enter student name: "; cin >> s[i].name; fflush(stdin);
   cout << "Enter student department: "; cin >> s[i].dept; fflush(stdin);
   cout << "Enter student session: "; cin >> s[i].session; fflush(stdin);
   cout << "Enter student email: "; cin >> s[i].email; fflush(stdin);
   cout << "Enter student phone: "; cin >> s[i].phone; fflush(stdin);
   i++; cout << "Student record added successfully" << endl;
}
void del_student_record(){
   system("clear");
   // find last three digit of student id and delete student record using array deletion
   cout << "Enter last three digit of student id: ";
   int id; cin >> id;
   for(int j = 0; j < i; j++){
       if(s[j].id == id){
           for(int k = j; k < i; k++){
               s[k] = s[k + 1];
           } i--;
           cout << "Student record deleted successfully" << endl; return;
       }
   }
}
void up_student_record(){
   system("clear");
   // find last three digit of student id and update student record using array updation
   cout << "Enter last three digit of student id: ";
   int id; cin >> id;

   for(int j = 0; j < n; j++){
       if(s[j].id == id){
           int choice;
           cout << "1. Update student name" << endl;
           cout << "2. Update student department" << endl;
           cout << "3. Update student session" << endl;
           cout << "4. Update student email" << endl;
           cout << "5. Update student phone" << endl;
           cout << "Enter your choice: ";cin >> choice;
           switch(choice){
               case 1:
                   cout << "Enter student name: "; cin >> s[j].name;
                   fflush(stdin); break;
               case 2:
                   cout << "Enter student department: "; cin >> s[j].dept;
                   fflush(stdin); break;
               case 3:
                   cout << "Enter student session: "; cin >> s[j].session;
                   fflush(stdin); break;
               case 4:
                   cout << "Enter student email: "; cin >> s[j].email;
                   fflush(stdin); break;
               case 5:
                   cout << "Enter student phone: "; cin >> s[j].phone;
                   fflush(stdin); break;
               default: cout << "Invalid choice" << endl; break;
           }
       }
   }
   cout << "Student record updated successfully" << endl;
}
// find student info by using their id
void find_student_by_id(){
   // sort students by id using bubble sort
   for(int j = 0; j < i; j++)
       for(int k = 0; k < i - j - 1; k++)
           if(s[k].id > s[k + 1].id) swap(s[k], s[k + 1]);
   // find student by id using binary search
   int id; cout << "Enter last three digit of student id: ";cin >> id;
   int low = 0, high = i - 1, mid;
   while(low <= high){
       mid = (low + high) / 2;
       if(s[mid].id == id){
           cout << "Student id: " << s[mid].id << endl;
           cout << "Student name: " << s[mid].name << endl;
           cout << "Student department: " << s[mid].dept << endl;
           cout << "Student session: " << s[mid].session << endl;
           cout << "Student email: " << s[mid].email << endl;
           cout << "Student phone: " << s[mid].phone << endl;
           return;
       }
       else if(s[mid].id < id) low = mid + 1;
       else high = mid - 1;
   }
   cout << "Student not found!" << endl;
}

void find_student_by_phone_number(){
   // find student by phone number using linear search
   string phone;
   cout << "Enter student phone number: ";
   cin >> phone;
   fflush(stdin);
   for(int j = 0; j < i; j++){
       if(s[j].phone == phone){
           cout << "Student id: " << s[j].id << endl;
           cout << "Student name: " << s[j].name << endl;
           cout << "Student department: " << s[j].dept << endl;
           cout << "Student session: " << s[j].session << endl;
           cout << "Student email: " << s[j].email << endl;
           cout << "Student phone: " << s[j].phone << endl;
           return;
       }
   } cout << "Student not found!" << endl;
}
void show_all_records(){
   system("clear");
   if(i == 0){cout << "No student record found!" << endl; return;}
   for(int j = 0; j < i; j++){
       cout << "Student id: " << s[j].id << endl;
       cout << "Student name: " << s[j].name << endl;
       cout << "Student department: " << s[j].dept << endl;
       cout << "Student session: " << s[j].session << endl;
       cout << "Student email: " << s[j].email << endl;
       cout << "Student phone: " << s[j].phone << endl;
       cout << endl;
   }
}
// author information
void author_details(){
   system("clear");
   printf("Author: Maruf Sarker\n");
   printf("Github: https://github.com/mdmarufsarker\n");
   printf("Email: mdmarufsarker.mms@gmail.com\n");
   printf("Website: https://marufsarker.netlify.app/\n");
}
// print sorry on the terminal
void sorry(){
   system("clear");
   printf("##### ###### ##### ##### #       #\n");
   printf("#     #    # #   # #   #  #     #\n");
   printf("#     #    # #   # #   #   #   #\n");
   printf("##### #    # ##### #####     #\n");
   printf("    # #    # # #   # #       #\n");
   printf("    # #    # #  #  #  #      #\n");
   printf("##### ###### #   # #   #     #   ## ## ##\n");  
}
// login functionality
void login(){
   string username, password;
   cout << "Enter username: ";cin >> username;
   cout << "Enter password: ";cin >> password;
   // Comparing username and password
   if(username == "admin" && password == "admin"){
       system("clear");
       printf("Login successful\n");
       printf("Welcome to student management system\n");
       printf("Loading...\n");
       system("clear");
       while(1){
           cout << "1. Add student record" << endl;
           cout << "2. Delete student record" << endl;
           cout << "3. Update student record" << endl;
           cout << "4. Find student by id" << endl;
           cout << "5. Find student by phone number" << endl;
           cout << "6. Show all records" << endl;
           cout << "7. Author details" << endl;
           cout << "8. Exit" << endl;
           cout << "Enter your choice: ";
           int choice; cin >> choice;
           switch(choice){
               case 1: add_student_record(); break;
               case 2: del_student_record(); break;
               case 3: up_student_record(); break;
               case 4: find_student_by_id(); break;
               case 5: find_student_by_phone_number(); break;
               case 6: show_all_records(); break;
               case 7: author_details(); break;
               case 8: sorry(); exit(0);
               default: cout << "Invalid choice" << endl;
           }
       }
   }else{
       system("clear");
       if(username != "admin") cout << "Username is incorrect" << endl;
       else if(password != "admin") cout << "Password is incorrect" << endl;
       else cout << "Username and password is incorrect" << endl;
   }
}
// global variables
#define LEN 50
char username[LEN] = "admin"; char password[LEN] = "admin";
int main() {
   int n = 3;
   while(n != 10){
       login();
       n--;
       cout << "You have " << n << " chances left" << endl;
   } sorry();
}
