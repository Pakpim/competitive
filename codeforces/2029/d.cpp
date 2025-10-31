#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5;
vector<ll> g[N];
vector<pair<ll,ll>> edge;
vector<vector<ll>> ans;
bool vis[N];

void dfs (int nn){
    for (auto e:g[nn]){
        if (!vis[e]) dfs(e);
        else{
            
        }
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll n,m;
        cin >> n >> m;
        for (int i=1;i<=m;i++){
            int u,v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        for (int i=1;i<=n;i++){
            if (!vis[i]) {
                dfs(i);
            }
        }
        for (int i=1;i<=n;i++) g[i].clear(),vis[i]=0;
    }
}