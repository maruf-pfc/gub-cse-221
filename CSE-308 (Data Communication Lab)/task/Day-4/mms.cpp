#include <bits/stdc++.h>
#include <debug.h>
using namespace std;

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

int toDecimal(const string& binaryNumber) {
    int decimalNumber = 0;
    int power = 0;
    
    for (int i = binaryNumber.length() - 1; i >= 0; --i) {
        if (binaryNumber[i] == '1') {
            decimalNumber += pow(2, power);
        }
        ++power;
    }
    
    return decimalNumber;
}

void binaryToDecimalWithValidityAndClassCheck(string s){
    stringstream ss(s);
    string oct = "";
    string res = "";
    int oct1, oct2, oct3, oct4;

    getline(ss, oct, '.');
    oct1 = toDecimal(oct);
    res += to_string(oct1);
    res += ".";

    getline(ss, oct, '.');
    oct2 = toDecimal(oct);
    res += to_string(oct2);
    res += ".";

    getline(ss, oct, '.');
    oct3 = toDecimal(oct);
    res += to_string(oct3);
    res += ".";

    getline(ss, oct);
    oct3 = toDecimal(oct);
    res += to_string(oct3);

    istringstream iss(res);
    string segment;
    int count = 0;
    
    while (getline(iss, segment, '.')) {
        count++;
        if (count > 4) {
            cout << "Invalid IP Address" << endl;
            return;
        }
        if (segment.empty() || segment.length() > 3){
            cout << "Invalid IP Address" << endl;
            return;
        }
        
        for (char c : segment) {
            if (!isdigit(c)){
            cout << "Invalid IP Address" << endl;
            return;
        }
        }
        
        int num = stoi(segment);
        if (num < 0 || num > 255) {
            cout << "Invalid IP Address" << endl;
            return;
        }
        
        if (num == 0 && segment.length() > 1){
            cout << "Invalid IP Address" << endl;
            return;
        }
    }
    
    if(count != 4){
        cout << "Invalid IP Address" << endl;
        return;
    }

    char ip_class = determineIPClass(res);
    cout << "Valid IP Address: " << res << endl;
    cout << "Class: " << ip_class << endl;
}

string toBinary(const string& decimalStr) {
    // Convert string to integer
    int decimal = stoi(decimalStr);
    
    if (decimal == 0)
        return "0";
    
    string binary = "";
    while (decimal > 0) {
        int remainder = decimal % 2;
        binary = to_string(remainder) + binary;
        decimal /= 2;
    }

    while (binary.length() < 8) {
        binary = "0" + binary;
    }
    return binary;
}

void decimalToBinaryWithValidityAndClassCheck(string s){
    stringstream ss(s);
    string oct = "";
    string res = "";
    string a, b, c, d;

    getline(ss, oct, '.');
    a = toBinary(oct);
    res += a;
    res += ".";

    getline(ss, oct, '.');
    b = toBinary(oct);
    res += b;
    res += ".";

    getline(ss, oct, '.');
    c = toBinary(oct);
    res += c;
    res += ".";

    getline(ss, oct);
    d = toBinary(oct);
    res += d;

    int cnt = 0;
    bool ok = false;

    for(auto ch : a){
        if(ch == '0') cnt++;
    }
    if(cnt == 8) ok = true;
    cnt = 0;
    
    for(auto ch : b){
        if(ch == '0') cnt++;
    }
    if(cnt == 8) ok = true;
    cnt = 0;
    
    for(auto ch : c){
        if(ch == '0') cnt++;
    }
    if(cnt == 8) ok = true;
    cnt = 0;
    
    for(auto ch : d){
        if(ch == '0') cnt++;
    }
    if(cnt == 8) ok = true;

    if(ok){
        cout << "Invalid IP Address" << endl;
        return;
    }

    cout << "Valid IP Address: " << res << endl;
    if(a[0] == '1' and a[1] == '1' and a[2] == '1' and a[3] == '1') cout << "Class E" << endl;
    else if(a[0] == '1' and a[1] == '1' and a[2] == '1' and a[3] == '0') cout << "Class D" << endl;
    else if(a[0] == '1' and a[1] == '1' and a[2] == '0') cout << "Class C" << endl;
    else if(a[0] == '1' and a[1] == '0') cout << "Class B" << endl;
    else cout << "Class A" << endl;
}

int main(){
    cout << "1. Binary Input?" << endl;
    cout << "2. Decimal Input?" << endl;
    cout << "Enter Your Choice: ";
    int choice;
    cin >> choice;

    cout << "Enter your IP : ";
    string s; cin >> s;

    switch(choice){
        case 1:
            binaryToDecimalWithValidityAndClassCheck(s);
            break;
        case 2:
            decimalToBinaryWithValidityAndClassCheck(s);
            break;
        default:
            cout << "Wrong Input!" << endl;
            break;
    }
}