// Write a program using recursive function that can convert a Decimal number to its equivalent Binary number.

#include <stdio.h>

int decToBin(int n){
    if(n == 0){
        return 0;
    }
    else{
        return (n % 2) + 10 * decToBin(n / 2);
    }
}

int main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        printf("%d\n", decToBin(n));
    }

    return 0;
}