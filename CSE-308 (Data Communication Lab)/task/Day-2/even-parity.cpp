#include<bits/stdc++.h>
using namespace std;

int main(){
    cout << "This is a program for even parity checking." << endl;
    cout << "Enter the data: ";

    string data = "";
    cin >> data;
    int n = data.size();

    int cnt = 0;
    for(auto ch : data){
        if(ch == '1') 
            cnt++;
    }

    string evenParity = "", oddParity = "";
    if(cnt % 2 == 0){
        evenParity += "1";
        evenParity += data; 
        cout << "After adding \'1\' at the front of the data: " << evenParity << endl;
    }else{
        oddParity += "0";
        oddParity += data;
        cout << "After adding \'0\' at the front of the data: " << oddParity << endl;
    }
}