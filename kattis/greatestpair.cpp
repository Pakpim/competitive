#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=200005,M=500005;
ll a[N],ans=0,sz[N],dist[N],mx[M],n,tmp=0;
bool vis[N];
vector<pair<ll,ll>> g[N];
vector <ll> del,fac[M];

void fsz(ll nn,ll np){
    sz[nn]=1;
    for (auto [xn,xw]:g[nn]) if (np!=xn && !vis[xn]){
        fsz(xn,nn);
        sz[nn]+=sz[xn];
    }
    return;
}

ll cen(ll nn,ll np,ll nsz){
    for (auto [xn,xw]:g[nn]) if (xn!=np && !vis[xn] && sz[xn]>nsz/2) return cen(xn,nn,nsz);
    return nn;
}

void fdist(ll nn,ll np,ll nd){
    dist[nn]=nd;
    for (auto [xn,xw]:g[nn]) if (xn!=np && !vis[xn]) fdist(xn,nn,nd+xw);
    return;
}

void find (ll nn,ll np){
    for (auto [xn,xw]:g[nn]) if (xn!=np && !vis[xn]) find(xn,nn);
    for (auto i:fac[a[nn]]){
        if (mx[i]!=-1e17) ans=max(ans,i*(dist[nn]+mx[i]));
    }
    return;
}

void fill (ll nn,ll np){
    for (auto [xn,xw]:g[nn]) if (xn!=np && !vis[xn]) fill(xn,nn);
    for (auto i:fac[a[nn]]){
        mx[i]=max(mx[i],dist[nn]);
        del.emplace_back(i);
    }
    return;
}

void dec(ll nn){
    fsz(nn,0);
    ll nc=cen(nn,0,sz[nn]);
    fdist(nc,0,0);
    for (auto i:fac[a[nc]]) mx[i]=0,mx[a[nc]/i]=0;
    for (ll i=0;i<g[nc].size();i++){
        auto [nt,nw]=g[nc][i];
        if (vis[nt]) continue;
        find(nt,nc);
        fill(nt,nc);
    }
    for (auto e:del) mx[e]=-1e17;
    del.clear();
    for (ll i=g[nc].size()-1;i>=0;i--){
        auto [nt,nw]=g[nc][i];
        if (vis[nt]) continue;
        find(nt,nc);
        fill(nt,nc);
    }
    for (auto e:del) mx[e]=-1e17;
    del.clear();
    for (auto i:fac[a[nc]]) mx[i]=-1e17,mx[a[nc]/i]=-1e17;
    vis[nc]=1;
    for (auto [xn,xw]:g[nc]) if (!vis[xn]) dec(xn);
    return;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    for (ll i=1;i<M;i++){
        for (ll j=i;j<M;j+=i){
            fac[j].emplace_back(i);
        }
    }
    do{
        cin >> n;
        tmp+=n;
        if (n==0) break;
        for (ll i=1;i<=n;i++) cin >> a[i];
        for (ll i=1;i<n;i++){
            ll u,v,w;
            cin >> u >> v >> w;
            g[u].emplace_back(v,w);
            g[v].emplace_back(u,w);
        }
        for (ll i=1;i<M;i++) mx[i]=-1e17;
        dec(1);
        cout << ans << '\n';
        for (int i=1;i<=n;i++) g[i].clear(),vis[i]=0;
        ans=0;
    }while (n!=0);
}