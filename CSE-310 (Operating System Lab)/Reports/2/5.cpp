// Write a Shell program to find the 2nd highest and 3rd highest numbers from a set of numbers and sum of them using array

#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "Enter the number of elements: ";
    int n; cin >> n;

    vector<int> v(n);
    int sum = 0;
    for(auto &i : v) cin >> i;

    sort(v.rbegin(), v.rend());

    cout << "2nd Highest: " << v[1] << endl;
    cout << "3rd Highest: " << v[2] << endl;
    cout << "Sum " << v[1] + v[2] << endl;
}