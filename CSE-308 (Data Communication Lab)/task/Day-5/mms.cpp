#include <bits/stdc++.h>
using namespace std;

void evenParity

int main(){
    cout << "1. Even Parity" << endl;
    cout << "2. Odd Parity" << endl << endl;
    int choice;
    cin >>  choice;

    cout << "Enter the data: ";
    string s;
    cin >> s;
    

    int one, zero;
    one = zero = 0;

    for(auto ch : s){
        if(ch == '1') one++;
        else zero++;
    }

    switch(choice){
        case 1:
            evenParity(s, one, zero);
            break;
        case 2:
            oddParity(s, one, zero);
            break;
        default:
            cout << "Wrong Input" << endl;
    }
}