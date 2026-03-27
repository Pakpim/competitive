#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e6+5, M=998244353;
ll par[N], sz[N], fr[N], to[N];
vector<int> g[N];

ll root (ll nn){
    if (!par[nn]) return nn;
    return par[nn]=root(par[nn]);
}

ll bp (ll a,ll b){
    ll re=1;
    while (b){
        if (b&1) re=(re*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return re;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> qu(n-1,{0,0});
    for (auto &[u,v]:qu) cin >> u >> v;
    for (int i=1;i<n;i++){
        cin >> fr[i] >> to[i];
        g[fr[i]].emplace_back(i);
        g[to[i]].emplace_back(i);
    }
    for (int i=1;i<=n;i++) sz[i]=1;
    ll den=1;
    for (auto [u,v]:qu){
        u=root(u); v=root(v);
        if (sz[u]>sz[v]) swap(u,v);
        bool f=0;
        for (auto e:g[u]){
            if (fr[e]==v || to[e]==v){
                f=1;
                continue;
            }
            if (fr[e]==u) fr[e]=v;
            if (to[e]==u) to[e]=v;
            g[v].emplace_back(e);
        }
        if (!f){
            cout << 0;
            return 0;
        }
        else den=(den*((sz[u]*sz[v])%M))%M;
        sz[v]+=sz[u];
        par[u]=v;
    }
    cout << bp(den,M-2);
}