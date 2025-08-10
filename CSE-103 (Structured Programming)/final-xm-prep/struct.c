#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i = 0;

struct student{
    char name[50];
    int id;
    float gpa;
    char skills[100];
} s[50];

void add_student();
void find_by_id();
void find_by_name();
void update_student();
void delete_student();
void show_all_details();

int main(){
    int choice;
    while(choice != 7){
        printf("------------Student Management System------------");
        printf("\n---------------------------------by Maruf Sarker\n");
        printf("1. Add student details.\n");
        printf("2. Find student details by id.\n");
        printf("3. Find student details by their first name.");
        printf("4. Update a student details.\n");
        printf("5. Delete a studetn details.\n");
        printf("6. Show all student details.\n");
        printf("7. Exit the program.\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_student();
                break;
            case 2:
                find_by_id();
                break;
            case 3:
                find_by_name();
                break;
            case 4:
                update_student();
                break;
            case 5:
                delete_student();
                break;
            case 6:
                show_all_details();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Wrong Choice.\n");
        }
    }
}

void add_student(){
    system("clear");
    printf("Student Name: ");
    scanf("%s", s[i].name);
    fflush(stdin);
    printf("Student ID: ");
    scanf("%d", &s[i].id);
    fflush(stdin);
    printf("Student GPA: ");
    scanf("%f", &s[i].gpa);
    fflush(stdin);
    printf("Top 3 Skills: \n");
    for(int m = 0; m < 3; m++){
        scanf("%s", s[i].skills[m]);
        fflush(stdin);
    }
    i++;
}
void find_by_id(){
    printf("Hi");
}
void find_by_name(){
    printf("Hi");
}
void update_student(){
    printf("Hi");
}
void delete_student(){
    printf("Hi");
}
void show_all_details(){
    printf("Hi");
}