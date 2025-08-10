#include <bits/stdc++.h>
using namespace std;

#define ll long long
const long long infLL = 9000000000000000000;

const int mx = 1e5 + 123;
vector<pair<int, int>> adj[mx];
long long dist[mx];

void dijkstra(int s, int n){ // TC: O(E + VlogV)
    for(int i = 0; i <= n; i++) dist[i] = infLL;
    dist[s] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq; // TC: O(logV)
    pq.push({0, s});

    while(!pq.empty()){
        int u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto it : adj[u]){
            int v = it.first;
            long long w = it.second;

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void solve(){
    int n, e;
    cin >> n >> e;

    for(int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dijkstra(0, n);

    for(int i = 0; i < n; i++){
        cout << i << " --> " << dist[i] << endl;
    }
    cout << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) solve();
}

/*
Input:
6 10
0 1 16
0 5 7
0 4 6
1 2 9
3 1 5
3 2 5
4 3 11
4 5 2
5 1 8
5 3 6

Output:
0 --> 0
1 --> 15
2 --> 18
3 --> 13
4 --> 6
5 --> 7
*/