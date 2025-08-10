// Note Management System

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i = 0;

// structure of all notes
struct note {
    char title[50];
    char content[500];
    char last_date[50];
    int id;
} n[50];

void add_note(){
    system("clear");
    printf("Add the Note Details\n");
    printf("-------------------------\n");
    // bug solved
    // user theke string input nile fflush(stdin) run kora lage. noile problem face korte hoy
    // like input nite dey na/ title input dile baki 2 ta kaj kore na auto function theke ber hoye jay.
    printf("Enter the Note Title: ");
    scanf("%s", n[i].title);
    fflush(stdin);
    printf("Enter the Note Description: ");
    scanf("%s", n[i].content);
    fflush(stdin);
    printf("Enter the Last Date: ");
    scanf("%s", n[i].last_date);
    fflush(stdin);
    // printf("Enter the Note ID\n");
    // scanf("%d", &n[i].id);
    n[i].id = i;
    i = i + 1;
}
void del_note(){
    system("clear");
    int x;
    printf("Enter the Note ID\n");
    scanf("%d", &x);

    for(int j = 0; j < i; j++){
        if(x == n[j].id){
            for(int k = j; k < i; k++){
                n[k] = n[k+1];
            }
            i = i - 1;
        }
    }
    printf("Note Deleted Successfully\n");
}

// bug: update isn't working
// bug solved used i but I have to use j
void up_note(){
    system("clear");
    int x;
    printf("Enter the Note ID\n");
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
                    printf("Enter the Note Title: ");
                    scanf("%s", n[j].title);
                    break;
                case 2:
                    printf("Enter the Note Description: ");
                    scanf("%s", n[j].content);
                    break;
                case 3:
                    printf("Enter the Last Date: ");
                    scanf("%s", n[j].last_date);
                    break;
                default:
                    printf("Invalid Choice\n");
                    break;
            }
        }
    }
    printf("Note Updated Successfully\n");
}
void find_by_title(){
    system("clear");
    char x[50];
    printf("Enter the Note Title\n");
    scanf("%s", x);

    for(int j = 0; j < i; j++){
        // it returns 0 if it is true
        // so we need to use != 0
        // way - 1 strcmp(x, n[j].title) == 0
        // way - 2 (!strstr(n[j].title, x))
        if(strcmp(x, n[j].title) == 0){
            printf("The Note Details are:\n");
            printf("ID: %d\n", n[j].id);
            printf("Title: %s\n", n[j].title);
            printf("Description: %s\n", n[j].content);
            printf("Last Date: %s\n", n[j].last_date);
        }
    }
}
void find_note(){
    system("clear");
    int x;
    printf("Enter the Note ID\n");
    scanf("%d", &x);

    for(int j = 0; j < i; j++){
        if(x == n[j - 1].id){
            printf("The Note Details are:\n");
            printf("ID: %d\n", n[j].id);
            printf("Title: %s\n", n[j].title);
            printf("Description: %s\n", n[j].content);
            printf("Last Date: %s\n\n", n[j].last_date);
        }
    }
}
void find_all_note(){
    system("clear");
    if(i == 0){
        printf("\nNo Note Found :(\n");
    }
    for(int j = 0; j < i; j++){
        printf("\n\nThe Note Details are\n");
        printf("ID: %d\n", n[j].id);
        printf("Title: %s\n", n[j].title);
        printf("Description: %s\n", n[j].content);
        printf("Last Date: %s\n\n", n[j].last_date);
    }  
}

void user_doc(){
    system("clear");
    printf("Whenever you give input for the \nnote title, description or last date \nyou need to write those data in the following format: \n\n");
    printf("Title: my-note-title\n");
    printf("Description: my-note-description\n");
    printf("Last Date: my-note-last-date\n\n");
    printf("github repo: https://github.com/maruf-sarker/gub-projects/tree/main/c/note-management-system");
}

void bug_report(){
    system("clear");
    printf("unable to update note, need to implement update function\n");
    printf("when you delete a note, the note id will be updated automatically\n");
}

int main(){
    while(1){
        printf("\n\t\tTask Management System\t\t\n");
        printf("---------------------------------------------------------\n\n");
        printf("List of all available commands:\n");
        printf("1. Add a new note\n");
        printf("2. Delete a note\n");
        printf("3. Update a note\n");
        printf("4. Find a note by id\n");
        printf("5. Find a note by title\n");
        printf("6. Find all notes\n");
        printf("7. Read the doc\n");
        printf("8. List of bugs\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_note();
                break;
            case 2:
                del_note();
                break;
            case 3:
                up_note();
                break;
            case 4:
                find_note();
                break;
            case 5:
                find_by_title();
                break;
            case 6:
                find_all_note();
                break;
            case 7:
                user_doc();
                break;
            case 8:
                bug_report();
                break;
            case 9:
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}