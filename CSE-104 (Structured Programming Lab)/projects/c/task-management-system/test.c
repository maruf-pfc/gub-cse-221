#include <stdio.h>
#include <string.h>

int main(){
    char title[50];
    char content[200];
    char last_date[50];

        printf("Add the Note Details\n");
        printf("-------------------------\n");
        printf("Enter the Note Title: ");
        scanf("%[^\n]%*c", title);
        printf("Enter the Note Description: ");
        scanf("%[^\n]%*c", content);
        printf("Enter the Last Date: ");
        scanf("%[^\n]%*c", last_date);

    printf("title: %s\n", title);
    printf("content: %s\n", content);
    printf("last_date: %s\n", last_date);
    return 0;
}
