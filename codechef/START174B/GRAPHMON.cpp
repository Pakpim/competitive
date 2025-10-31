#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5;
ll a[N],b[N],par[N],h[N],dp[N],mx;
vector<ll> g[N];
deque <tuple<ll,ll,ll>> ed;

ll root (ll nn){
    if (!par[nn]) return nn;
    return par[nn]=root(par[nn]);
}

void uni(ll u,ll v){
    ll ru=root(u);
    ll rv=root(v);
    if (ru==rv) return;
    if (h[ru]>h[rv]) swap(ru,rv);
    par[ru]=rv;
    h[rv]=max(h[rv],h[ru]+1);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll n,m;
        cin >> n >> m;
        mx=0;
        ed.clear();
        for (ll i=1;i<=n;i++) g[i].clear(),par[i]=0,h[i]=1,dp[i]=0;
        for (ll i=1;i<=n;i++) cin >> a[i];
        for (ll i=1;i<=n;i++) cin >> b[i];
        while (m--){
            ll u,v;
            cin >> u >> v;
            ed.emplace_back(max(a[u],a[v]),u,v);
        }
        sort(ed.begin(),ed.end());
        while (!ed.empty()){
            auto [nw,nu,nv]=ed.front();
            ed.pop_front();
            uni(nu,nv);
        }
    }
}