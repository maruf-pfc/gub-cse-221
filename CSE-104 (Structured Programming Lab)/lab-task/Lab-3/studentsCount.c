#include<stdio.h>

int main(){
    int n;

    printf("Enter the student count: ");
    scanf("%d", &n);

    // if(n > 15){
    //     printf("Sir will deliver new lecture.\n");
    // }else{
    //     printf("Sir will deliver a repeat lecture.\n");
    // }

    if(n > 15){
        printf("Sir will deliver new lecture.\n");
    }else if(n <= 15 && n > 0){
        printf("Sir will deliver a repeat lecture.\n");
    }else{
        printf("Class Cancel.\n");
    }

    return 0;
}