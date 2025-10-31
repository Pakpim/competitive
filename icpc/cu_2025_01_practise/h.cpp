#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ti = tuple<ll,ll,ll>;
const ll N=1e5+5,inf=1e18;
vector<tuple<ll,ll>> g[N];
priority_queue<ti,vector<ti>,greater<ti>> pq;
ll par[N],dis[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    while (m--){
        ll u,v,w;
        cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    for (int i=1;i<=n;i++) dis[i]=inf;
    pq.emplace(0,n,n);
    while(!pq.empty()){
        auto [nd,nn,np]=pq.top(); pq.pop();
        if (par[nn]) continue;
        par[nn]=np;
        for (auto [xn,xw]:g[nn]){
            if (dis[xn]>nd+xw){
                dis[xn]=nd+xw;
                pq.emplace(nd+xw,xn,nn);
            }
        }
    }
    if (dis[1]==inf){
        cout << "-1";
        exit(0);
    }
    int nn=1;
    while (par[nn]!=nn){
        cout << nn << ' ';
        nn=par[nn];
    }
    cout << nn;
}