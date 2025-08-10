// In the name of Allah, Most Merciful
// Written by: Md. Maruf Sarker
// Problem Link: 
// Date: 2024-03-09

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

char determineIPClass(const string &ip_address) {
    stringstream ss(ip_address);
    string octet;
    getline(ss, octet, '.');

    int oct1 = stoi(octet);

    if (oct1 >= 0 && oct1 <= 126) return 'A';
    else if (oct1 >= 128 && oct1 <= 191) return 'B';
    else if (oct1 >= 192 && oct1 <= 223) return 'C';
    else if (oct1 >= 224 && oct1 <= 239) return 'D';
    else return 'E';
}

string ipToBinary(const string &ip_address) {
    stringstream ss(ip_address);
    string octet;
    string binary_ip;

    // Convert each octet to binary
    while (getline(ss, octet, '.')) {
        int octet_value = stoi(octet);
        binary_ip += bitset<8>(octet_value).to_string();
        binary_ip += '.'; // Add dot after each octet
    }

    // Remove the last dot
    binary_ip.pop_back();

    return binary_ip;
}

void solve(int t){
    string s;
    cin >> s;

    int cnt = 0;
    for(auto c : s){
        if(c == '.'){
            cnt++;
        }
    }
    
    if(s[0] == '0' or cnt != 3){
        cout << "Invalid IP Address" << endl;
        return;
    }

    stringstream ss(s);
    string oct;
    int oct1, oct2, oct3, oct4;

    getline(ss, oct, '.');
    // dbg(oct);
    if (oct.size() > 1 && oct[0] == '0') {
        cout << "Invalid IP Address" << endl;
        return;
    }
    oct1 = stoi(oct);

    getline(ss, oct, '.');
    // dbg(oct);
    if (oct.size() > 1 && oct[0] == '0') {
        cout << "Invalid IP Address" << endl;
        return;
    }
    oct2 = stoi(oct);

    getline(ss, oct, '.');
    // dbg(oct);
    if (oct.size() > 1 && oct[0] == '0') {
        cout << "Invalid IP Address" << endl;
        return;
    }
    oct3 = stoi(oct);

    getline(ss, oct);
    if (oct.size() > 1 && oct[0] == '0') {
        cout << "Invalid IP Address" << endl;
        return;
    }
    oct4 = stoi(oct);

    if((oct1 < 0 or oct1 > 255) or (oct2 < 0 or oct2 > 255) or (oct3 < 0 or oct3 > 255) or (oct4 < 0 or oct4 > 255)){
        cout << "Invalid IP Address" << endl;
        return;
    }

    char ip_class = determineIPClass(s);
    cout << "Valid IP Address, Class: " << ip_class << endl;
    string binary_ip = ipToBinary(s);
    cout << "Binary representation of IP address " << endl;
    cout << s << ": " << binary_ip << " : ";

    for(int i = 0; i < binary_ip.size(); i++){
        if(s[i] == '0'){
            cout << "Class A" << endl;
            break;
        }else if(s[i] == '1' and s[i + 1] == '0'){
            cout << "Class B" << endl;
            break;
        }else if(s[i] == '1' and s[i + 1] == '1' and s[i + 2] == '0'){
            cout << "Class C" << endl;
            break;
        }else if(s[i] == '1' and s[i + 1] == '1' and s[i + 2] == '1' and s[i + 3] == '0'){
            cout << "Class D" << endl;
            break;
        }else{
            cout << "Class E" << endl;
            break;
        }
    }
}

int main() {
    Maruf
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) solve(i);
}
