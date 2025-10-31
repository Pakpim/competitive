#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 2e18;

struct mtx{
    int d;
    vector<vector<ll>> v;
    mtx(int d):d(d){
        v.resize(d, vector<ll> (d,inf));
        for (int i=0;i<d;i++) v[i][i]=0;
    }
    mtx(vector<vector<ll>> v):d(v.size()),v(v){}
    mtx operator *= (const mtx &o){
        vector<vector<ll>> tmp(d, vector<ll> (d,inf));
        for (int i=0;i<d;i++){
            for (int j=0;j<d;j++){
                for (int k=0;k<d;k++) if (v[i][k]<inf && o.v[k][j]<inf) tmp[i][j]=min(tmp[i][j],v[i][k]+o.v[k][j]);
            }
        }
        v=tmp;
        return *this;
    }
    friend mtx operator* (const mtx &lhs,const mtx &rhs){return mtx(lhs)*=rhs;}
};

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<ll>> tmp(n, vector<ll> (n,inf));
    while (m--){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        tmp[v-1][u-1]=w;
    }
    mtx a(n),b(tmp);
    while (k>0){
        if (k&1) a*=b;
        b*=b;
        k>>=1;
    }
    ll ans = inf;
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) if (a.v[i][j]<inf) ans=min(ans,a.v[i][j]);
    if (ans<inf) cout << ans;
    else cout << "IMPOSSIBLE";
}