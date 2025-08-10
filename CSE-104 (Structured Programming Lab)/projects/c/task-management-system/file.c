// problem name
#include<stdio.h>
#include<math.h>
int main() {
    FILE *ptr;
    ptr = fopen("data.txt", "w");

    int n, roll;
    char name[100];

    printf("Enter total number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter roll number: ");
        scanf("%d", &roll);
        printf("Enter name: ");
        scanf("%s", name);
        fprintf(ptr, "%d %s\n", roll, name);
    }

return 0;
}