// Suppose you have some words and you want to right justify them, that is, align them to the right. Create a program that reads some words and print it all right justified, in the same order as they appear in the input

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    printf("Enter the number of test cases: ");
    int t;
    scanf("%d", &t);
    char str[50][100]; // N (1 ≤ N ≤ 50)

    int n = t;

    while(t--){
        int max = 0;
        for (int i = 0 ; i < n; i++){
            scanf("%s", str[i]);
        }
        for (int i = 0; i < n; i++){
            if(strlen(str[i]) > max)
                max = strlen(str[i]);
        }
        for (int i = 0; i < n; i++){
            printf("%*s", max, str[i]);
            printf("\n");
        }
    }
    return 0;
}