// 1. Implement byte stuffing algorithm in C++ where the FLAG is "GALF" and the ESCAPE sequence is
// "EPACSE". The program should prompt the user to input data and perform byte stuffing according to

// the specified protocol, inserting the ESCAPE sequence before any occurrence of the FLAG or ESCAPE

// sequence. After the byte-stuffing process, the program should display the resulting stuffed data.

// – Input- This is some data GALF and EPACSE another GALF example EPACSE data

// – Output- GALFThis is some data EPACSEGALF and EPACSEEPACSE another EPACSEGALF example EPACSEEPACSE dataGALF

// In the name of Allah, Most Merciful
// Written by: Md. Maruf Sarker
// Problem Link: 
// Date: 2024-03-18

#include <bits/stdc++.h>
#include <debug.h>
using namespace std;

#define ll long long
#define endl "\n"
#define sp " "
#define Maruf ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

class Solution {
public:
    
};

int main() {
    cout << "Enter your data: ";
    string s; getline(cin, s);

    string key = "GALF", ans = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'G' and s[i + 1] == 'A' and s[i + 2] == 'L' and s[i + 3] == 'F'){
            ans += "EPACSEGALF";
            i += 3;
        }else if(s[i] == 'E' and s[i + 1] == 'P' and s[i + 2] == 'A' and s[i + 3] == 'C' and s[i + 4] == 'S' and s[i + 5] == 'E'){
            ans += "EPACSEEPACSE";
            i += 5;
        }else{
            ans += s[i];
        }
    }

    cout << endl << key + ans + key << endl;
}