#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N=1e5+5,M=3e5+5;
vector<tuple<int,int>> g[N];
ll f[M],t[M],cnt;
bool vis[N];

void dfs (int nn,int nm){
    if (vis[nn]) return;
    vis[nn]=1;
    cnt++;
    for (auto [e,i]:g[nn]){
        if (!nm){
            if (!f[i]) {
                f[i]=nn;
                t[i]=e;
                dfs(e,nm);
            }
        }
        else{
            if (e==f[i]) {
                dfs(e,nm);
            }
        }
    }
    return;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m;
    cin >> n >> m;
    for (int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        g[u].emplace_back(v,i);
        g[v].emplace_back(u,i);
    }
    dfs(1,0);
    for (int i=0;i<=n;i++) vis[i]=0;
    cnt=0;
    dfs(1,1);
    // cout << '\n';
    // for (int i=0;i<m;i++) cout << f[i] << ' ' << t[i] << '\n';
    if (cnt==n){
        // cout << "ok";
        for (int i=0;i<m;i++) cout << f[i] << ' ' << t[i] << '\n';
    }
    else{
        cout << 0;
    }
}