#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N=1e5+5;
vector<ll> g[N];
ll c[N],sz[N],hv[N],mx[N],cnt[N];
map<ll,ll> mp;

void dfs(ll nn,ll np){
    sz[nn]=1;
    ll mx=0;
    for (auto e:g[nn]) if (e!=np){
        dfs(e,nn);
        sz[nn]+=sz[e];
        if (sz[e]>mx) hv[nn]=e,mx=sz[e];
    }
    return;
}

void dfs3 (ll nn,ll np,ll root){
    for (auto e:g[nn]) if (e!=np) dfs3(e,nn,root);
    mp[c[nn]]++;
    ll nv = mp[c[nn]];
    if (nv>mx[root]){
        mx[root]=nv;
        cnt[root]=0;
    }
    if (nv==mx[root]) cnt[root]+=c[nn];
}

void dfs2 (ll nn,ll np){
    for (auto e:g[nn]) if (e!=np && e!=hv[nn]){
        dfs2(e,nn);
        mp.clear();
    }
    if (hv[nn]){
        dfs2(hv[nn],nn);
    }
    mx[nn]=mx[hv[nn]];
    cnt[nn]=cnt[hv[nn]];
    for (auto e:g[nn]) if (e!=np && e!=hv[nn]){
        dfs3(e,nn,nn);
    }
    mp[c[nn]]++;
    ll nv = mp[c[nn]];
    if (nv>mx[nn]){
        mx[nn]=nv;
        cnt[nn]=0;
    }
    if (nv==mx[nn]) cnt[nn]+=c[nn];
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    for (ll i=1;i<=n;i++) cin >> c[i];
    for (ll i=1;i<n;i++){
        ll u,v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1,0);
    dfs2(1,0);
    for (ll i=1;i<=n;i++) cout << cnt[i] << ' ';
}