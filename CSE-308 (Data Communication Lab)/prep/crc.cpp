#include <bits/stdc++.h>
using namespace std;

string calculateCRC(const string &data, const string &divisor) {
    string crc = data;
    int n = data.size();
    int m = divisor.size();
    
    for (int i = 0; i <= n - m; ) {
        for (int j = 0; j < m; j++)
            crc[i + j] = crc[i + j] == divisor[j] ? '0' : '1';
        
        while (i < crc.size() && crc[i] != '1') 
            i++;
    }

    return crc.substr(n);
}

// Function to append CRC to the data
string appendCRC(const string &data, const string &divisor) {
    string augmentedData = data + string(divisor.size() - 1, '0');
    string crc = calculateCRC(augmentedData, divisor);
    return data + crc;
}

// Function to verify the received data using CRC
bool verifyCRC(const string &data, const string &divisor) {
    string crc = calculateCRC(data, divisor);
    return crc.find('1') == string::npos; // No errors if all bits in CRC are 0
}

int main() {
    string data = "11010011101100";
    string divisor = "1101";

    string codeWord = appendCRC(data, divisor);
    cout << "Original Data: " << data << endl;
    cout << "Code Word (Data + CRC): " << codeWord << endl;

    string receivedData = codeWord;
    bool isValid = verifyCRC(receivedData, divisor);
    if (isValid) cout << "Data received correctly (no errors)." << endl;
    else cout << "Data received with errors." << endl;
}
