// Write a Shell program to find total number of alphabets, digits or special characters in a string.

#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "Enter data: ";
    string s;
    getline(cin, s);

    int alpha, digits, specialChar;
    alpha = digits = specialChar = 0;

    for(auto ch : s){
        if((ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z')) alpha++;
        else if(ch >= '0' and ch <= '9') digits++;
        else specialChar++;
    }

    cout << "Alphabets = " << alpha << endl;
    cout << "Digits = " << digits << endl;
    cout << "Special Characters = " << specialChar << endl;
}