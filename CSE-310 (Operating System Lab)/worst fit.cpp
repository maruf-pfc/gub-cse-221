// In the name of Allah, Most Merciful
// Written by: Md. Maruf Sarker
// Problem Link: 
// Date: 2024-05-02

#include <bits/stdc++.h>
// #include <debug.h>
using namespace std;

#define ll long long
#define endl "\n"
#define sp " "
#define Maruf ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

class Solution {
public:
    
};

#define mx 25

void maruf(){
    vector<int> frag(mx), b(mx), f(mx), bf(mx), ff(mx);

    frag.clear();
    b.clear();
    f.clear();
    bf.clear();
    ff.clear();

    cout << "Enter the number of blocks: ";
    int nb; cin >> nb;
    cout << "Enter the number of files: ";
    int nf; cin >> nf;

    cout << "\nEnter the size of the blocks-\n";
    for(int i = 1; i <= nb; i++){
        cout << "Block " << i << " : ";
        cin >> b[i];
    }

    cout << "Enter the size of the files:-\n";
    for(int i = 1; i <= nf; i++){
        cout << "File: " << i << " : ";
        cin >> f[i];
    }

    int highest, free;
    highest = free = 0;
    for(int i = 1; i <= nf; i++){
        for(int j = 1; j <= nb; j++){
            if(bf[j] != 1){
                free = b[j] - f[i];
                if(free > 0){
                    if(highest < free){
                        ff[i] = j;
                        highest = free;
                    }
                }
            }
        }
        frag[i] = highest;
        bf[ff[i]] = 1;
        highest = 0;
    }

    cout << "\nFile_no \tFile_size \tBlock_no \tBlock_size \tFragment" << endl;
    for(int i = 1; i <= nf; i++){
        cout << i << "\t\t" << f[i] << "\t\t" << ff[i] << "\t\t" << b[ff[i]] << "\t\t" << frag[i] << endl;
    }
}

int main() {
    maruf();
}