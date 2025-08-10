// Task Management System

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i = 0;

// structure of all Tasks
struct Task {
    char title[50];
    char content[500];
    char last_date[50];
    int id;
} n[50];

// add a new Task
void add_Task(){
    system("clear");
    printf("Add the Task Details\n");
    printf("-------------------------\n");
    printf("Enter the Task Title: ");
    scanf("%s", n[i].title);
    fflush(stdin);
    printf("Enter the Task Content: ");
    scanf("%s", n[i].content);
    fflush(stdin);
    printf("Enter the Last Date: ");
    scanf("%s", n[i].last_date);
    fflush(stdin);
    n[i].id = i;
    i = i + 1;
    system("clear");
}

// delete a single Task
void del_Task(){
    system("clear");
    int x;
    printf("Enter the Task ID\n");
    scanf("%d", &x);

    for(int j = 0; j < i; j++){
        if(x == n[j].id){
            for(int k = j; k < i; k++){
                n[k] = n[k+1];
            }
            i = i - 1;
        }
    }
    printf("Task Deleted Successfully\n");
}

// update a single Task
void up_Task(){
    system("clear");
    int x;
    printf("Enter the Task ID\n");
    scanf("%d", &x);

    for(int j = 0; j < i; j++){
        if(x == n[j].id){
            printf("Choose what you want to update\n");
            printf("1. Title\n");
            printf("2. Description\n");
            printf("3. Last Date\n");

            int choice;
            scanf("%d", &choice);

            switch(choice){
                case 1:
                    printf("Enter the Task Title: ");
                    scanf("%s", n[j].title);
                    // fgets(n[j].title, 50, stdin);
                    fflush(stdin);
                    break;
                case 2:
                    printf("Enter the Task Content: ");
                    scanf("%s", n[j].content);
                    // fgets(n[j].content, 500, stdin);
                    fflush(stdin);
                    break;
                case 3:
                    printf("Enter the Last Date: ");
                    scanf("%s", n[j].last_date);
                    // fgets(n[j].last_date, 50, stdin);
                    fflush(stdin);
                    break;
                default:
                    printf("Invalid Choice\n");
                    break;
            }
        }
    }
    printf("Task Updated Successfully\n");
}

// find a Task by its title
void find_by_title(){
    system("clear");
    char x[50];
    printf("Enter the Task Title\n");
    scanf("%s", x);

    for(int j = 0; j < i; j++){
        if(strcmp(x, n[j].title) == 0){
            printf("The Task Details are:\n");
            printf("ID: %d\n", n[j].id);
            printf("Title: %s\n", n[j].title);
            printf("Description: %s\n", n[j].content);
            printf("Last Date: %s\n", n[j].last_date);
        }
    }
}

// find a single Task
void find_Task(){
    system("clear");
    int x;
    printf("Enter the Task ID\n");
    scanf("%d", &x);

    for(int j = 0; j < i; j++){
        if(x == n[j].id){
            printf("The Task Details are:\n");
            printf("ID: %d\n", n[j].id);
            printf("Title: %s\n", n[j].title);
            printf("Description: %s\n", n[j].content);
            printf("Last Date: %s\n\n", n[j].last_date);
        }
    }
}

// find all Tasks
void find_all_Task(){
    system("clear");
    if(i == 0){
        printf("\nNo Task Found :(\n");
    }
    for(int j = 0; j < i; j++){
        printf("\nThe Task Details are\n");
        printf("ID: %d\n", n[j].id);
        printf("Title: %s\n", n[j].title);
        printf("Description: %s\n", n[j].content);
        printf("Last Date: %s\n", n[j].last_date);
    }  
}

// user documentation
void user_doc(){
    system("clear");
    printf("Whenever you give input for the \nTask title, description or last date \nyou need to write those data in the following format: \n\n");
    printf("Title: my-Task-title\n");
    printf("Description: my_Task_description\n");
    printf("Last Date: my_Task_last_date\n\n");
    printf("github repo: https://github.com/maruf-sarker/gub-projects/tree/main/c/Task-management-system");
}

// bug report
void bug_report(){
    system("clear");
    printf("\n");
    printf("when you delete a Task, the Task id will be updated automatically\n");
}

// author information
void author(){
    system("clear");
    printf("Author: Maruf Sarker\n");
    printf("Github: https://github.com/mdmarufsarker\n");
    printf("Email: mdmarufsarker.mms@gmail.com\n");
    printf("Phone: +8801843579712\n");
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
    printf("Enter username: ");
    char username[50];
    scanf("%s", username);
    fflush(stdin);
    printf("Enter password: ");
    char password[50];
    scanf("%s", password);
    fflush(stdin);

    // Comparing username and password
    if((!strcmp(username, "admin")) && (!strcmp(password, "admin"))){
        system("clear");
        while(1){
            printf("\n\t\tTask Management System\t\t\n");
            printf("---------------------------------------------------------\n\n");
            printf("List of all available commands:\n");
            printf("1. Add a new Task\n");
            printf("2. Delete a Task\n");
            printf("3. Update a Task\n");
            printf("4. Find a Task by id\n");
            printf("5. Find a Task by title\n");
            printf("6. Find all Tasks\n");
            printf("7. Read the documentation\n");
            printf("8. Author details\n");
            printf("9. List of bugs\n");
            printf("10. Exit\n");

            printf("Enter your choice: ");
            int choice;
            scanf("%d", &choice);

            switch(choice){
                case 1:
                    add_Task();
                    break;
                case 2:
                    del_Task();
                    break;
                case 3:
                    up_Task();
                    break;
                case 4:
                    find_Task();
                    break;
                case 5:
                    find_by_title();
                    break;
                case 6:
                    find_all_Task();
                    break;
                case 7:
                    user_doc();
                    break;
                case 8:
                    author();
                    break;
                case 9:
                    bug_report();
                    break;
                case 10:
                    exit(1);
                    break;
                default:
                    printf("Invalid choice\n");
                    break;
            }
        }
    }else{
        system("clear");
        if(!strcmp(username, "admin")){
            printf("Invalid Password\n");
        }else if(!strcmp(password, "admin")){
            printf("Invalid Username\n");
        }else{
            printf("Invalid Username and Password\n");
        }
        
        
    }
}

// global variables
#define LEN 50
char username[LEN] = "admin";
char password[LEN] = "admin";

// main function
int main(){
    int n = 3;
    while(n != 10){
        login();
        n--;
        printf("You have %d attempts left\n", n);
    }
    sorry();

    return 0;
}