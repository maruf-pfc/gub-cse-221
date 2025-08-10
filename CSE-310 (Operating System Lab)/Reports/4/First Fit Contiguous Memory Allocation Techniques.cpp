#include <bits/stdc++.h>
using namespace std;

#define mx 25
int main(){
    vector<int> frag(mx), b(mx), f(mx), bf(mx), ff(mx);

    cout << "Enter the number of blocks: ";
    int nb; cin >> nb;
    cout << "Enter the number of files: ";
    int nf; cin >> nf;
    
    cout << "\nEnter the size of the blocks:-" << endl;
    for(int i = 1; i <= nb; i++){
        cout << "Block " << i << ": ";
        cin >> b[i];
    }
    cout << "Enter the size of the files:-" << endl;
    for(int i = 1; i <= nf; i++){
        cout << "File " << i << ": ";
        cin >> f[i];
    }

    int temp;
    for(int i = 1; i <= nf; i++){
        for(int j = 1; j <= nb; j++){
            if(bf[j] != 1){
                temp = b[j] - f[i];
                if(temp >= 0){
                    ff[i] = j;
                    break;
                }
            }
        }
        frag[i] = temp;
        bf[ff[i]] = 1;
    }

    cout << "\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement";
    for(int i = 1; i <= nf; i++){
        cout << "\n" << i << "\t\t" << f[i] << "\t\t" << ff[i] << "\t\t" << b[ff[i]] << "\t\t" << frag[i];
    }
    cout << endl;
}