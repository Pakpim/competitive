#include<bits/stdc++.h>
#include<vector>
using namespace std;

using ll=long long;
using pi=pair<int,int>;
const int N=10005;
ll dis[N];
vector<pair<ll, ll>> g[N];
priority_queue<pair<ll, ll>> pq;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m,q,k,p,s;
    cin >> n >> m >> k >> p >> s;
    while (m--){
        ll u,v,w;
        cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    for (int i=1;i<=n;i++) dis[i]=1e9;
    dis[s]=0;
    pq.emplace(0,s);
    while (!pq.empty()){
        auto [nd,nn] = pq.top();
        pq.pop();
        if (dis[nn]<=nd) continue;
        for (auto [xn,xd]:g[nn]){
            if (dis[xn]>nd+xd){
                dis[xn]=nd+xd;
                pq.emplace(nd+xd,xn);
            }
        }
    }
    if (dis[p]<=k){
        pq.emplace(0,p);
        while (!pq.empty()){
            auto [nd,nn] = pq.top();
            pq.pop();
            if (dis[nn]<=nd) continue;
            for (auto [xn,xd]:g[nn]){
                if (dis[xn]>nd+xd){
                    dis[xn]=nd+xd;
                    pq.emplace(nd+xd,xn);
                }
            }
        }
    }
    for (int i=1;i<=n;i++) cout << dis[i] << ' ';
}