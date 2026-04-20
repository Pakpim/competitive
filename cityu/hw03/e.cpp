#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int a[N], mn[N], mx[N], par[N], in[N], ans;
vector<int> g[N], rg[N], c[N], g2[N], t;
bool vis[N],vis2[N],ok[N], ok2[N];

void dfs(int nn){
    if (vis[nn]) return;
    vis[nn]=1;
    for (auto e:g[nn]){
        dfs(e);
    }
    t.emplace_back(nn);
    return;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    while (m--){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].emplace_back(v);
        rg[v].emplace_back(u);
        if (w==2){
            g[v].emplace_back(u);
            rg[u].emplace_back(v);
        }
    }
    queue<int> q;
    q.emplace(1);
    while (!q.empty()){
        auto nn = q.front(); q.pop();
        if (ok[nn]) continue;
        ok[nn]=1;
        for (auto e:g[nn]) q.emplace(e);
    }
    q.emplace(n);
    while (!q.empty()){
        auto nn = q.front(); q.pop();
        if (ok2[nn]) continue;
        ok2[nn]=1;
        for (auto e:rg[nn]) q.emplace(e);
    }
    dfs(1);
    while (!t.empty()){
        auto np=t.back(); t.pop_back();
        if (vis2[np]) continue;
        q.emplace(np);
        while (!q.empty()){
            auto nn=q.front(); q.pop();
            if (vis2[nn]) continue;
            vis2[nn]=1;
            c[np].emplace_back(nn);
            par[nn]=np;
            for (auto e:rg[nn]) q.emplace(e);
        }
    }
    for (int i=1;i<=n;i++) mn[i]=1e9;
    for (int i=1;i<=n;i++){
        for (auto e:c[i]){
            mn[i]=min(mn[i], a[e]);
            mx[i]=max(mx[i], a[e]);
            for (auto x:g[e]){
                if (par[x]!=par[e]){
                    g2[i].emplace_back(par[x]);
                    in[par[x]]++;
                }
            }
        }
    }
    // for (int i=1;i<=n;i++){
    //     cout << i << " : ";
    //     for (auto e:c[i]) cout << e << ' ';
    //     cout << " = " << mn[i] << ' ' << mx[i] << ' '  << par[i] << ' ' << in[i] << ' ' << ok2[i] << " : ";
    //     for (auto e:g2[i]) cout << e << ' '; cout << '\n';
    // }
    for (int i=1;i<=n;i++) if (par[i]==i && in[i]==0) q.emplace(i);
    while (!q.empty()){
        auto nn=q.front(); q.pop();
        if (!ok2[nn]) continue;
        ans=max(ans, mx[nn]-mn[nn]);
        for (auto e:g2[nn]){
            mn[e]=min(mn[e],mn[nn]);
            in[e]--;
            if (in[e]==0) q.emplace(e);
        }
    }
    cout << ans;
}

/*
5 5
4 3 5 6 1
1 2 1
1 4 1
2 3 1
3 5 1
4 5 1
*/