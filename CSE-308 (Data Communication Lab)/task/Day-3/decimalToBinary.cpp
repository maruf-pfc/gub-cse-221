// In the name of Allah, Most Merciful
// Written by: Md. Maruf Sarker
// Problem Link: 
// Date: 2024-03-09

#include <bits/stdc++.h>
// #include <debug.h>
using namespace std;

#define ll long long
#define endl "\n"
#define sp " "
#define Maruf ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

class Solution {
public:
    
};

void solve(int t){
    int decimalNumber;
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;
    
    cout << "Binary equivalent: " << bitset<8>(decimalNumber) << endl;


    string binaryNumber;
    cout << "Enter a binary number: ";
    cin >> binaryNumber;
    
    bitset<8> bitset(binaryNumber);
    int decimalNumber = bitset.to_ulong();
    
    cout << "Decimal equivalent: " << decimalNumber << endl;
}

int main() {
    Maruf
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) solve(i);
}