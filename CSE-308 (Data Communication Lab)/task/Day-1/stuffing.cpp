#include <bits/stdc++.h>
using namespace std;

void bitStuffing(int n, vector<int> &arr){
    vector<int> res(n + 1);

    int i, j, k;
    i = j = 0;
    int cnt = 1;

    while(i < n){
        if(arr[i] == 1){
            res[j] = arr[i];

            for(k = i + 1; arr[k] == 1 and k < n and cnt < 5; k++){
                j++;
                res[j] = arr[k];
                cnt++;

                if(cnt == 5){
                    j++;
                    res[j] = 0;
                }
                i = k;
            }
        }else{
            res[j] = arr[i];
        }
        i++;
        j++;
    }

    for(auto i : res){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    int n = 6;
    vector<int> v = {1, 1, 1, 1, 1, 1};
    bitStuffing(n, v);
}