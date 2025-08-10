// problem name
#include<stdio.h>
#include<math.h>

int i = 0;

struct note {
    char title[50];
    char content[500];
    char last_date[50];
    int id;
} n[50];

void add_note(){
    fgets(n[i].title, 50, stdin);
    fflush(stdin);
    fgets(n[i].content, 500, stdin);
    fflush(stdin);
    fgets(n[i].last_date, 50, stdin);
    n[i].id = i + 1;
    i++;
}
int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    add_note();
        
    for(int j = 0; j < i; j++){
        printf("\nThe Note Details are\n");
        printf("\nID: %d\n", n[j].id);
        printf("Title: %s", n[j].title);
        printf("Description: %s", n[j].content);
        printf("Last Date: %s\n", n[j].last_date);
    }  

return 0;
}