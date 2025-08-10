// breath first search algorithm implementation

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, e, u, v, s;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    vector <int> adj[n+1];
    for(int i=0; i<e; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "Enter source node: ";
    cin >> s;
    queue <int> q;
    vector <int> visited(n+1, 0);
    q.push(s);
    visited[s] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(!visited[v]){
                q.push(v);
                visited[v] = 1;
            }
        }
    }
    cout << endl;
    return 0;
}