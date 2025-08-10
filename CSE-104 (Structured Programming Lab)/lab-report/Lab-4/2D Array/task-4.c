// CSE 104 course is taught in M sections and each section contains N students. Store all the student’s marks in a 2D array. Print the sections with highest and lowest marks.

#include <stdio.h>

int main() {
    int m, n, i, j, sum = 0, max, min;
    printf("Enter the number of sections and students: ");
    scanf("%d%d", &m, &n);
    int marks[m][n];

    for (i = 0; i < m; i++) {
        printf("Enter the marks of section %d: ", i + 1);
        for (j = 0; j < n; j++) {
            scanf("%d", &marks[i][j]);
        }
    }

    // Finding the section with highest marks
    max = marks[0][0];
    min = marks[0][0];
    int maxSection = 0, minSection = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (marks[i][j] > max) {
                max = marks[i][j];
                maxSection = i;
            }
            if (marks[i][j] < min) {
                min = marks[i][j];
                minSection = i;
            }
        }
    }

    printf("The section %d with highest marks is: %d\n", maxSection + 1, max);
    printf("The section %d with lowest marks is: %d\n", minSection + 1, min);

return 0;
}