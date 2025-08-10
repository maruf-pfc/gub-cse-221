// 2. Implement a bit-Stuffing & De- Stuffing algorithm in C/C++/Java and verify its functionality with a
// sample input. You are provided with a sample input data sequence, and your task is to stuff it using your

// algorithm. Additionally, there will be a fixed header and trailer, "01111110" at the beginning and end

// of the data sequence, respectively.Stuffing-

// – Sample Input: 01111110 1111111111 01111110

// – Sample Output: 01111110 111110111110 01111110

// De Stuffing-

// – Sample Input: 01111110 111110111110 01111110

// – Sample Output: 01111110 1111111111 01111110


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

void bitStuffing(){
    cout << "Input: ";
    string s;
    cin >> s;

    string key = "01111110";
    // string input = "01111110111111111101111110";
    
    // removing header & trailer
    s.erase(0, 8);
    s.erase(s.length() - 8);
    
    string ans;
    int cnt = 0;

    for (char c : s) {
        ans += c;
        if (c == '1') {
            cnt++;
            if (cnt == 5) {
                ans += '0';
                cnt = 0;
            }
        } else cnt = 0;
    }

    cout << "Output: " << key + ans + key << endl;
}

void bitDeStuffing(){
    cout << "Input: ";
    string s;
    cin >> s;

    // removing header & trailer
    s.erase(0, 8);
    s.erase(s.length() - 8);

    string key = "01111110";
    string ans = "";

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1' and s[i + 1] == '1' and s[i + 2] == '1' and s[i + 3] == '1' and s[i + 4] == '1' and s[i + 5] == '0'){
            ans += "11111";
            i += 5;
        }else ans += s[i];
    }
    
    cout << "Output: " << key + ans + key << endl;
}

int main() {
    cout << "1. Bit Stuffing\n";
    cout << "2. Bit De-Stuffing\n";
    cout << "Enter your choice: ";
    int choice; cin >> choice;

    switch(choice){
        case 1:
            bitStuffing();
            break;
        case 2:
            bitDeStuffing();
            break;
        default:
            cout << "Wrong Input\n";
            break;
    }
}