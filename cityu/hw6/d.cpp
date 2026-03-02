#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=2e5+5;
int par[N], sz[N];

int root(int nn){
    if (!par[nn]) return nn;
    return par[nn]=root(par[nn]);
}

bool uni(int u,int v){
    u=root(u), v=root(v);
    if (u==v) return 0;
    if (sz[u]>sz[v]) swap(u,v);
    par[u]=v;
    sz[v]+=sz[u];
    return 1;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<tuple<ll,ll,ll>> ed1, ed2;
    while (m--){
        ll u,v,w;
        cin >> u >> v >> w;
        if (w<=k) ed1.emplace_back(-w,u,v);
        ed2.emplace_back(max(0ll,w-k),u,v);
    }
    sort(ed1.begin(),ed1.end());
    sort(ed2.begin(),ed2.end());
    ll cnt=0, sum=0, ans=1e18;
    for (int i=1;i<=n;i++) par[i]=0, sz[i]=1;
    for (auto [w,u,v]:ed1){
        cnt+=uni(u,v);
    }
    if (cnt>=n-1){
        ans = k+get<0>(ed1.front());
    }
    for (int i=1;i<=n;i++) par[i]=0, sz[i]=1;
    bool f=0;
    for (auto [w,u,v]:ed2){
        if (uni(u,v)) sum+=w;
        f|=w>0;
    }
    if (f) ans=min(ans,sum);
    cout << ans;
}