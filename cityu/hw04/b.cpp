#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using tll = tuple<ll,ll,ll>;
const int N=1e5+5;
vector<tuple<ll,ll>> g[N];
priority_queue<tll,vector<tll>,greater<tll>> pq;
ll dist[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) dist[i]=1e18;
    while (m--){
        ll u,v,w;
        cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    ll sum=0;
    pq.emplace(0,0,1);
    while (!pq.empty()){
        auto [nd,nw,nn]=pq.top();
        pq.pop();
        if (nd>=dist[nn]) continue;
        dist[nn]=nd;
        sum+=nw;
        for (auto [xn,xw]:g[nn]){
            pq.emplace(nd+xw,xw,xn);
        }
    }
    
    cout << sum;
}