#include <bits/stdc++.h>
using namespace std;

// wa

const int N=10005;
vector<pair<int,int>> g[N],v[N];
vector<tuple<int,int,int>> g2[N];
int dp1[N],dp2[N], vis[N],t;

void dfs (int nn,int np,int b){
    vis[nn]=++t;
    for (auto [xn,xw,xi]:g2[nn]){
        if (b&(1<<xi) && !vis[xn]){
            dfs(xn,nn,b);
            v[nn].emplace_back(xn,xw);
            dp1[nn]+=dp2[xn];
        }
    }
    for (auto [xn,xw]:g[nn]){
        if (!vis[xn]) {
            dfs(xn,nn,b);
            v[nn].emplace_back(xn,xw);
            dp1[nn]+=dp2[xn];
        }
    }
    dp2[nn]=dp1[nn];
    for (auto [xn,xw,xi]:g2[nn]){
        if (vis[xn]>vis[nn] && b&(1<<xi)) dp2[nn]=max(dp2[nn],dp1[xn]+dp1[nn]-dp2[xn]+xw);
    }
    for (auto [xn,xw]:g[nn]){
        if (vis[xn]>vis[nn]) dp2[nn]=max(dp2[nn],dp1[xn]+dp1[nn]-dp2[xn]+xw),cout << " --> " << nn << ' ' << xn << ' ' << dp1[xn]+dp1[nn]-dp2[xn]+xw << '\n';
    }
    v[nn].clear();
    cout << " => " << nn  << ' ' << dp1[nn] << ' ' << dp2[nn] << '\n';
    return;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k,ans=0;
    cin >> n >> k;
    for (int i=1;i<n;i++){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    for (int i=0;i<k;i++){
        int u,v,w;
        cin >> u >> v >> w;
        g2[u].emplace_back(v,w,i);
        g2[v].emplace_back(u,w,i);
    }
    for (int i=0;i<1<<k;i++){
        for (int j=1;j<=n;j++) vis[j]=dp1[j]=dp2[j]=0;
        cout << bitset<10>(i) << '\n';
        dfs(1,0,i);
        ans=max(ans,dp2[1]);
    }
    cout << ans;
}