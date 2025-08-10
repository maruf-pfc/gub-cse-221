// In the name of Allah, Most Merciful
// Written by: Md. Maruf Sarker
// Problem Link: 
// Date: 2024-03-26

#include <bits/stdc++.h>
// #include <debug.h>
using namespace std;

#define ll long long
#define endl "\n"
#define sp " "
#define Maruf ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool isEvenParity(const string& bitStream) {
    int count = 0;
    for (char bit : bitStream) {
        if (bit == '1') {
            count++;
        }
    }
    return (count % 2 == 0);
}

bool isOddParity(const string& bitStream) {
    return !isEvenParity(bitStream);
}

int main() {
    string bitStream;
    
    cout << "Enter bit stream: ";
    cin >> bitStream;

    if (bitStream.find_first_not_of("01") != -1) {
        cout << "Invalid bit stream" << endl;
        return 1;
    }

    cout << (isEvenParity(bitStream) ? "Even parity" : "Odd parity") << endl;
}