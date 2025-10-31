#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=100005;
vector<ll> g[N];
ll sz[N],ans[N],n;

void dfs(ll nn,ll np){
    sz[nn]=1;
    for (auto e:g[nn]) if (e!=np){
        dfs(e,nn);
        sz[nn]+=sz[e];
        ans[nn]+=sz[e]*(n-sz[e]);
    }
    ans[nn]+=(n-sz[nn])*sz[nn]+n-1;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (ll i=1;i<n;i++){
        ll u,v;
        cin >> u >> v;
        u++;
        v++;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1,0);
    for (ll i=1;i<=n;i++) cout << ans[i]/2 << '\n';
}