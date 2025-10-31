#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using db=double;
const ll N=2e5+5,inf=1e9;
ll p[N],v[N],par[N],t[N],c[2][N],h[N];
priority_queue<tuple<db,ll,ll>> pq;

ll root (ll nn){
    if (!par[nn]) return nn;
    return par[nn]=root(par[nn]);
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,ans=0;
    cin >> n;
    for (ll i=2;i<=n;i++) cin >> p[i];
    for (ll i=1;i<=n;i++) cin >> v[i];
    for (ll i=1;i<=n;i++){
        if (v[i]==0) pq.emplace(inf,i,0);
        else pq.emplace(0,i,0);
        c[v[i]][i]=1;
    }
    while (pq.size()>0){
        auto [nv,nn,nt]=pq.top(); pq.pop();
        if (t[nn]>nt || !p[nn]) continue;
        ll np=root(p[nn]);
        t[nn]++;
        t[np]++;
        ans+=c[0][nn]*c[1][np];
        if (h[nn]>h[np]){
            swap(nn,np);
            p[np]=p[nn];
        }
        h[np]=max(h[np],h[nn]+1);
        par[nn]=np;
        c[0][np]+=c[0][nn];
        c[1][np]+=c[1][nn];
        db xv;
        if (c[1][np]==0) xv=inf;
        else xv=db(c[0][np])/db(c[1][np]);
        pq.emplace(xv,np,t[np]);
    }
    cout << ans;
}