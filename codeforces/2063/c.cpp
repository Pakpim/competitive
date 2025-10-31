#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ti=tuple<ll,ll,ll>;
const int N=2e5+5;
ll ar[N],dp[N][5][5],ans=0;
vector<ll> g[N];

void dfs (int nn,int np){
    dp[nn][0][1]=dp[nn][0][2]=dp[nn][1][0]=dp[nn][1][1]=dp[nn][1][2]=-1e9;
    dp[nn][1][1]=g[nn].size();
    for (auto e:g[nn]) if (e!=np) dfs(e,nn);
    ll sz=g[nn].size(),mx1=-1e9,mx2=-1e9;
    for (auto e:g[nn]){
        if (e==np) continue;
        dp[nn][0][1]=max({dp[nn][0][1],dp[e][0][1],dp[e][1][1]});
        dp[nn][0][2]=max({dp[nn][0][2],dp[e][0][2],dp[e][1][2]});
        dp[nn][1][2]=max({dp[nn][1][2],dp[e][0][1]+sz-1,dp[e][1][1]+sz-2});
        mx2=max({mx2,dp[e][0][1],dp[e][1][1]});
        if (mx2>mx1) swap(mx1,mx2);
    }
    dp[nn][0][2]=max(dp[nn][0][2],mx1+mx2-1);
    // cout << nn << " => " << dp[nn][0][1] << ' ' << dp[nn][0][2] << ' ' << dp[nn][1][1] << ' ' << dp[nn][1][2] << '\n';
    ans=max({ans,dp[nn][0][2],dp[nn][1][2]});
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        ans=-1e9;
        for (int i=1;i<n;i++){
            int u,v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(1,0);
        cout << ans << '\n';
        for (int i=0;i<=n;i++){
            g[i].clear();
            for (int j=0;j<2;j++) for (int k=0;k<3;k++) dp[i][j][k]=-1e9;
        }
    }
}