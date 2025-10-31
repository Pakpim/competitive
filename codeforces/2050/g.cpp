#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using db=double;
const ll N=2e5+5;
ll dp[N],n,ans;
vector<int> g[N];

void dfs(int nn,int np){
    dp[nn]=g[nn].size();
    deque<ll> tmp;
    for (auto e:g[nn]) {
        if (e!=np){
            dfs(e,nn);
            tmp.emplace_back(dp[e]);
            sort(tmp.begin(),tmp.end());
            if (tmp.size()>2)tmp.pop_front();
            dp[nn]=max(dp[nn],dp[e]+ll(g[nn].size())-2);
            // cout << nn << ' ' << e << " = " << dp[e]+ll(g[nn].size())-1 << '\n';
        }
    }
    // cout << " => " << nn << ' ' << dp[nn] << '\n';
    ans=max(ans,dp[nn]);
    if (tmp.size()==2){
        ll nv=g[nn].size()+tmp[0]+tmp[1]-4;
        ans=max(ans,nv);
    }
}

void solve(){
    cin >> n;
    ans=1;
    for (int i=1;i<=n;i++) dp[i]=0,g[i].clear();
    for (int i=1;i<n;i++) {
        int u,v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1,0);
    cout << ans << '\n';
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}