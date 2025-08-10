// In the name of Allah, Most Merciful
// Written by: Md. Maruf Sarker
// Problem Link: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// Date: 2023-11-10

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define sp " "
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define asort(x) x.begin(), x.end()
#define dsort(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define mod 1000000007
#define mem(a, b) memset(a, b, sizeof(a))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))
#define dxR = {0, 0, 1, -1}
#define dyR = {1, -1, 0, 0}
#define dxQ = {0, 0, 1, -1, 1, 1, -1, -1}
#define dyQ = {1, -1, 0, 0, 1, -1, 1, -1}
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define setprecision(x) cout << fixed << setprecision(x)
#define Maruf ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;

template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
#define dbg(args...) do {cerr << #args << " : "; mms(args); } while(0)
void mms(){cerr << endl;}
template<typename T>void mms(T a[],int n){for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
template<typename T,typename...hello>void mms(T arg,const hello&...rest){cerr<<arg<<' ';mms(rest...);}

void maruf(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
bool isPrime(int n){ // TC: O(sqrt(n)), SC: O(1)
    if(n == 1 or n % 2 == 0) return false;
    if(n == 2) return true;
    for(int i = 3; i * i <= n; i += 2){
        if(n % i == 0) return false;
    }
    return true;
}

const int mx = 1e5 + 123;
vpii adj[mx];
ll dist[mx];

void dijkstra(int s, int n){ // TC: O(E + VlogV)
    for(int i = 0; i <= n; i++) dist[i] = infLL;
    dist[s] = 0;
    priority_queue<pll, vpll, greater<pll>> pq; // TC: O(logV)
    pq.push({0, s});

    while(!pq.empty()){
        int u = pq.top().ss;
        ll d = pq.top().ff;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto it : adj[u]){
            int v = it.ff;
            ll w = it.ss;

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void solve(){
    // int n = 6, e = 10;

    // adj[0].pb({1, 16});
    // adj[0].pb({5, 7});
    // adj[0].pb({4, 6});
    // adj[1].pb({2, 9});
    // adj[3].pb({1, 5});
    // adj[3].pb({2, 5});
    // adj[4].pb({3, 11});
    // adj[4].pb({5, 2});
    // adj[5].pb({1, 8});
    // adj[5].pb({3, 6});

    int n, e;
    cin >> n >> e;

    for(int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
    }

    dijkstra(0, n);

    for(int i = 0; i < n; i++){
        cout << i << " --> " << dist[i] << endl;
    }
    cout << endl;
}

int main() {
    Maruf
    clock_t z = clock();

    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) solve();

    cerr << "Run Time : " << (((double)(clock() - z)) / CLOCKS_PER_SEC) << endl;
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