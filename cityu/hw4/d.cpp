#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=1e3+5;
deque<tuple<ll,ll,ll>> edge;
ll par[N], h[N], d[N], c[N];

int root (int nn){
    if (!par[nn]) return nn;
    return root(par[nn]);
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m,k;
    cin >> n >> m >> k;
    while (m--){
        ll u,v,w;
        cin >> u >> v >> w;
        edge.emplace_back(w,u,v);
    }
    sort(edge.begin(),edge.end());
    while (!edge.empty()){
        auto [w,u,v]=edge.front();
        edge.pop_front();
        u=root(u); v=root(v);
        if (u==v) continue;
        if (h[u]>h[v]) swap(u,v);
        par[u]=v;
        c[u]=w;
        h[v]=max(h[v],h[u]+1);
    }
    for (int i=1;i<=n;i++){
        int nn=i, nr=root(i);
        while (nn!=nr){
            d[i]++;
            nn=par[nn];
        }
    }
    while (k--){
        ll s,t, ans=0;
        cin >> s >> t;
        if (root(s)!=root(t)){
            cout << "-1\n";
            continue;
        }
        if (d[s]<d[t]) swap(s,t);
        while (d[s]>d[t]){
            ans=max(ans,c[s]);
            s=par[s];
        }
        while(s!=t){
            ans=max({ans,c[s],c[t]});
            s=par[s];
            t=par[t];
        }
        cout << ans << '\n';
    }
}