#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=200005;
vector<ll> g[N];
ll ans=1e18,dp[N],mn[N],pos[N],dp2[N];

void dfs(ll nn,ll np){
    dp[nn]=1;
    mn[nn]=1e18;
    for (auto e:g[N]){
        if (e!=np) dfs(e,nn);
    }
    for (auto e:g[N]){
        if (e!=np){
            dp[nn]+=dp[e]<<1;
            mn[nn]=min(mn[nn],dp[e]);
        }
    }
}

void dfs2(int nn,int np){
    for (auto e:g[N]){
        if (e!=np) dfs2(e,nn);
    }
    if (g[nn].size()>2) return;
    dp[nn]=
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,rt;
    bool ok=1;
    cin >> n >> m;
    for (int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        if (g[u].size()>3 || g[v].size()>3) ok=0;
    }
    if (m!=n-1 || !ok){
        cout << "NIE";
        return;
    }
    for (int i=1;i<=n;i++) if (g[i].size()<=2) rt=i;
    dfs(rt,0);
    dfs2(rt,0);
}