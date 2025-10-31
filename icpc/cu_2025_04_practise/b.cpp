#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=1e5+5;
vector<tuple<ll,ll>> edge;
int par[N],h[N];

int root (int nn){
    if (!par[nn]) return nn;
    return par[nn]=root(par[nn]);
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<n;i++){
        ll u,v;
        cin >> u >> v;
        edge.emplace_back(u,v);
    }
    vector<tuple<ll,ll>> del;
    int cnt = 0;
    for (auto [u,v]:edge){
        if (root(u) == root(v)){
            del.emplace_back(u,v);
            cnt++;
        }
        else{
            u=root(u); v=root(v);
            if (h[u]>h[v]) swap(u,v);
            par[u]=v;
            h[v]=max(h[v],h[u]+1);
        }
    }
    cout << cnt << '\n';
    for (int i=1;i<=n;i++){
        if (root(i)!=root(1)){
            auto [a,b] = del.back();
            del.pop_back();
            cout << a << ' ' << b << ' ' << i << ' ' << 1 << '\n';
            int u=root(i), v=root(1);
            if (h[u]>h[v]) swap(u,v);
            par[u]=v;
            h[v]=max(h[v],h[u]+1);
        }
    }
}