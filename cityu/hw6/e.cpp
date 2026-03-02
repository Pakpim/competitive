#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5;
ll par[N], sz[N], sum;

ll root(ll nn){
    if (!par[nn]) return nn;
    return par[nn]=root(par[nn]);
}

bool uni(ll u,ll v, ll w){
    u=root(u), v=root(v);
    if (u==v) return 0;
    if (sz[u]>sz[v]) swap(u,v);
    sum+=(sz[u]*sz[v])*(w+1)-1;
    par[u]=v;
    sz[v]+=sz[u];
    return 1;
}

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    vector<tuple<ll,ll,ll>> edge;
    for (ll i=1;i<n;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        edge.emplace_back(w,u,v);
    }
    sort(edge.begin(),edge.end());
    for (ll i=1;i<=n;i++) par[i]=0, sz[i]=1;
    for (auto [w,u,v]:edge){
        uni(u,v,w);
    }
    cout << sum;
}

/*
5
1 2 1
1 3 1
1 4 1
1 5 1
*/