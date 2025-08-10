#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Enter the number of blocks-- ";
    int nb; cin >> nb;
    vector<int> blocks(nb, 0);
    for(int i = 1; i <= nb; i++){
        cout << "Block " << i << ": ";
        cin >> blocks[i];
    }

    cout << "Enter the number of processes-- ";
    int np; cin >> np;
    vector<int> processes(np, 0);
    for (int i = 1; i <= np; i++) {
        cout << "Enter memory required for process " << i << ": ";
        cin >> processes[i];
    }

    cout << "\nProcesses\tProcesses Size\tBlocks\tBlocks Size\tAllocated\tInt. Frag.\n";
    vector<int> allocation(nb, -1);
    int i, j;
    for(i = 1; i <= np; i++){
        int flag = 0;
        for(j = 1; j <= nb; j++){
            if(blocks[j] >= processes[i] and allocation[j] == -1){
                allocation[j] = i;
                int intFrag = blocks[j] - processes[i];
                cout << i << "\t\t" << processes[i] << "\t\t" << j << "\t\t" << blocks[j] << "\t\t" << "YES" << "\t\t" << intFrag << endl;
                flag = 1;
                break;
            }
        }
        if(!flag) cout << i << "\t\t" << processes[i] << "\t\t" << i << "\t\t" << blocks[i] << "\t\t" << "NO" << "\t\t" << 0 << endl;
    }
}