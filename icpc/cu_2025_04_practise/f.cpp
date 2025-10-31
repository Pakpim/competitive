#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=1e5+5;
vector<tuple<ll,ll,ll>> edge;
int par[N],h[N];

int root (int nn){
    if (!par[nn]) return nn;
    return par[nn]=root(par[nn]);
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    while (m--){
        ll u,v,w;
        cin >> u >> v >> w;
        edge.emplace_back(w,u,v);
    }
    ll sum=0;
    sort(edge.begin(), edge.end());
    for (auto [w,u,v]:edge){
        u=root(u), v=root(v);
        if (u==v) continue;
        if (h[u]>h[v]) swap(u,v);
        par[u]=v;
        h[v]=max(h[v],h[u]+1);
        sum+=w;
    }
    cout << sum;
}