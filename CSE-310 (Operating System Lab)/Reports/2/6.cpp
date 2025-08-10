// Write a Shell program to find the factorial of two different numbers and sum of the numbers using function.

#include <bits/stdc++.h>
using namespace std;

long long fact(int n){
    long long ans = 1;
    for(int i = 1; i <= n; i++) ans *= i;
    return ans;
}

int main(){
    cout << "Enter 2 numbers: ";
    int n1, n2;
    cin >> n1 >> n2;

    cout << "Sum = " << fact(n1) + fact(n2) << endl;
}