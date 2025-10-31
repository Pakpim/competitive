#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=200005;

int par[N],h[N],cnt;

int root (int nn){
    if (!par[nn]) return nn;
    return par[nn]=root(par[nn]);
}

void uni(int u,int v){
    // cout << " => " << u << ' ' << v << '\n';
    u=root(u); v=root(v);
    if (u==v) return;
    if (h[u]>h[v]) swap(u,v);
    par[u]=v;
    h[v]=max(h[v],h[u]+1);
    cnt--;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll n,m;
        cin >> n >> m;
        cnt=n;
        vector<pair<ll,ll>> q[15][15];
        while (m--){
            ll a,d,k;
            cin >> a >> d >> k;
            q[d][a%d].emplace_back(a,a+d*k);
        }
        for (int i=1;i<11;i++){
            for (int j=0;j<i;j++){
                sort(q[i][j].begin(),q[i][j].end());
                ll p=0;
                for (int k=0;k<q[i][j].size();k++){
                    auto [nl,nr]=q[i][j][k];
                    nl=max(p,nl);
                    for (int u=nl;u<nr;u+=i){
                        uni(u,u+i);
                    }
                    p=max(p,nr);
                }
            }
        }
        cout << cnt << '\n';
        for (int i=1;i<=n;i++) par[i]=h[i]=0;
    }
}