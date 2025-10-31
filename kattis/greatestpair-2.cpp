#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=200005,M=500005;
ll n,a[N],ans=0,dist[N],h[N],t[N],ti=1,sp1[N][20],sp2[N][20];
vector<pair<ll,ll>> g[N];
vector <ll> fac[M],v[M],v2;
bool f[M];

void dfs (ll nn,ll np){
    for (auto [xn,xw]:g[nn]){
        if (xn!=np) {
            dist[xn]=dist[nn]+xw;
            h[xn]=h[nn]+1;
            dfs(xn,nn);
            sp1[ti][0]=h[nn];
            sp2[ti][0]=nn;
            t[xn]=ti++;
        }
    }
    return;
}

ll lca (ll na,ll nb){
    if (na==nb) return na;
    if (t[na]>t[nb]) swap(na,nb);
    int d=log2(t[nb]-t[na]);
    int r=max(1ll,t[nb]-(1<<d));
    // cout << na << ' ' << nb << " => " << t[na] << ' ' << t[nb] << ' ' << d << ' ' << r << ' ' << sp2[t[na]][d] << ' ' << sp2[r][d] << '\n';
    return sp1[t[na]][d]<sp1[r][d] ? sp2[t[na]][d]:sp2[r][d];
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (ll i=1;i<M;i++){
        for (ll j=i;j<M;j+=i){
            fac[j].emplace_back(i);
        }
    }
    while(1){
        cin >> n;
        if (n==0) break;
        for (ll i=1;i<=n;i++) {
            cin >> a[i];
            for (auto e:fac[a[i]]){
                v[e].emplace_back(i);
                if (!f[e]) v2.emplace_back(e);
                f[e]=1;
            }
        }
        for (ll i=1;i<n;i++){
            ll u,v,w;
            cin >> u >> v >> w;
            g[u].emplace_back(v,w);
            g[v].emplace_back(u,w);
        }
        dist[1]=0; h[1]=0;
        dfs(1,0);
        t[1]=ti;
        sp1[ti][0]=h[1];
        sp2[ti][0]=1;
        for (ll i=1;i<19;i++){
            for (ll j=1;j<=n;j++){
                ll r=min(n-1,j+(1<<(i-1)));
                sp1[j][i]=min(sp1[j][i-1],sp1[r][i-1]);
                sp2[j][i]=sp1[j][i-1]<sp1[r][i-1] ? sp2[j][i-1]:sp2[r][i-1];
                // cout << i << ' ' << j << " => " << sp1[j][i] << ' ' << sp2[j][i] << " : " << r << ' ' << sp1[j][i-1] << ' ' << sp1[r][i-1] << '\n';
            }
        }
        for (auto i:v2){
            if (v[i].size()<2) continue;
            ll tn=v[i][0],mx1=tn,mx2,mxd1=0,mxd2=0;
            for (auto e:v[i]){
                ll nd=dist[tn]+dist[e]-2*dist[lca(tn,e)];
                if (nd>mxd1){
                    mxd1=nd;
                    mx1=e;
                }
            }
            for (auto e:v[i]){
                ll nd=dist[mx1]+dist[e]-2*dist[lca(mx1,e)];
                if (nd>mxd2){
                    mxd2=nd;
                    mx2=e;
                }
                // mxd1=max(mxd1,nd);
            }
            mxd1=max(mxd1,mxd2);
            for (auto e:v[i]){
                ll nd=dist[mx2]+dist[e]-2*dist[lca(mx2,e)];
                mxd1=max(mxd1,nd);
            }
            ans=max(ans,mxd1*i);
            // cout << " => " << mxd1 << ' ' << i << '\n';
        }
        cout << ans << '\n';
        for (ll i=1;i<=n;i++) g[i].clear();
        for (auto i:v2) v[i].clear(),f[i]=0;
        v2.clear();
        ans=0;
        ti=1;
    }
}

/*
7
10 10 10 10 10 10 10
1 2 1
2 5 1
2 6 1
3 1 1
7 4 1
4 1 1
0
*/