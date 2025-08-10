#include <bits/stdc++.h>
using namespace std;

int main() {
    string bitStream;
    cout << "Enter the bit stream: ";
    cin >> bitStream;

    int countOnes = 0;
    for(char bit : bitStream) {
        if(bit == '1') {
            countOnes++;
        }
    }

    cout << (countOnes % 2 == 0 ? "Error detected" : "No error detected") << "\n";
}
