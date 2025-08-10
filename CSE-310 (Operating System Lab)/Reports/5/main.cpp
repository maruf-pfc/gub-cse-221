#include <bits/stdc++.h>
using namespace std;
#define mxPages 50
#define mxFrames 20
int main(){
    int pageFault = 0;
    vector<int> pages(mxPages), memory(mxFrames), pageFreq(mxPages, 0);
    int totalPage, totalFrame, memoryIndex = 0;
    cout << "Enter total number of pages: ";
    cin >> totalPage;
    cout << "Enter the pages: ";
    for(int i = 0; i < totalPage; i++) cin >> pages[i];
    cout << "Enter total number of frames: ";
    cin >> totalFrame;
    for(auto &frame : memory) frame = -1;
    cout << "Page Replacement Process is -->\n";

    int i, j;
    for(i = 0; i < totalPage; i++){
        int pageFound = 0;
        for(j = 0; j < totalFrame; j++){
            if(memory[j] == pages[i]){
                pageFreq[pages[i]]++;
                pageFound = 1;
                break;
            }
        }

        cout << "Page: " << pages[i] << " --> ";

        if(!pageFound){
            if(memoryIndex < totalFrame){
                memory[memoryIndex] = pages[i];
                pageFreq[pages[i]]++;
                memoryIndex++;
            }else{
                int leastFreq = INT_MAX, leastFreqIndex = -1;
                for(j = 0; j < totalFrame; j++){
                    if(pageFreq[memory[j]] < leastFreq){
                        leastFreq = pageFreq[memory[j]];
                        leastFreqIndex = j;
                    }
                }
                memory[leastFreqIndex] = pages[i];
                pageFreq[pages[i]]++;
                pageFault++;
            }

            for(j = 0; j < totalFrame; j++){
                if(memory[j] == -1) cout << " - ";
                else cout << " " << memory[j];
            }
        }
        cout << "\nNo Page Fault\n";
    }

    cout << "Total Page Fault: " << pageFault << endl;
}

/*
Input:
10
7 0 1 2 0 3 0 4 2 3
3

Output:
*/