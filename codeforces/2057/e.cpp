#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ti=tuple<int,int,int>;
const ll N=405,M=80005;
ll dis[N][M];
vector<pair<int,int>> g[N];
priority_queue<ti,vector<ti>,greater<ti>> pq; 

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,m,q;
        cin >> n >> m >> q;
        while (m--){
            int u,v,w;
            cin >> u >> v >> w;
            g[u].emplace_back(v,w);
            g[v].emplace_back(u,w);
        }
        
    }
}