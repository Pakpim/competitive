#include <bits/stdc++.h>
using namespace std;

const int N=5005;
vector<int> g[N],rg[N],g2[N];
deque<int> dq;
queue<pair<int,int>> q;
int par[N],in[N],r[N],cnt[N],mx;
bool vis[N];

void dfs (int nn){
    vis[nn]=1;
    for (auto e:g[nn]){
        if (!vis[e]) dfs(e);
    }
    dq.emplace_back(nn);
}

void dfs2 (int nn,int nr){
    vis[nn]=1;
    par[nn]=nr;
    for (auto e:rg[nn]) if (!vis[e]) dfs2(e,nr);
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    while (m--){
        int u,v;
        cin >> u >> v;
        g[u].emplace_back(v);
        rg[v].emplace_back(u);
    }
    for (int i=0;i<n;i++){
        if (!vis[i]) dfs(i);
    }
    for (int i=0;i<n;i++) vis[i]=0;
    while (!dq.empty()){
        int nn = dq.back();
        dq.pop_back();
        if (vis[nn]) continue;
        dfs2(nn,nn);
    }
    for (int i=0;i<n;i++){
        for (auto e:g[i]){
            if (par[i]==par[e]) continue;
            g2[par[i]].emplace_back(par[e]);
            in[par[e]]++;
        }
    }
    for (int i=0;i<n;i++){
        vis[i]=0;
        if (par[i]==i && !in[i]) q.emplace(i,1);
    }
    while (!q.empty()){
        auto [nn,nr]=q.front();
        q.pop();
        if (vis[nn]) continue;
        // cerr << " => " << nn << ' ' << nr << '\n';
        vis[nn]=1;
        r[nn]=nr;
        mx=max(mx,nr);
        for (auto e:g2[nn]){
            in[e]--;
            if (!in[e]) q.emplace(e,nr+1);
        }
    }
    for (int i=0;i<n;i++) cnt[r[par[i]]]++;
    for (int i=1;i<=mx;i++) cout << cnt[i] << ' ';
}