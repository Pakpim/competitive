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
    int n;
    cin >> n;
    for (int i=0;i<=n;i++) sz[i]=1;
    vector<tuple<ll,ll,ll>> edge;
    for (int i=1;i<=n;i++){
        ll w;
        cin >> w;
        edge.emplace_back(w,0,i);
    }
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++){
        ll w;
        cin >> w;
        if (i>j) edge.emplace_back(w,i,j);
    }
    sort(edge.begin(),edge.end());
    ll sum=0;
    for (auto [w,u,v]:edge){
        if (uni(u,v)) sum+=w;
    }
    cout << sum;
}