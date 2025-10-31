#include <bits/stdc++.h>
using namespace std;


using ll=long long;
using pll=pair<ll,ll>;
const ll N=4e5+5;
vector<pll> g[N],rg[N];
vector<ll> g2[N],rg2[N];
queue<ll> q;  
priority_queue<pll,vector<pll>,greater<pll>> pq;
bool f[N],vis[N];
ll dis[N],dp[N],n,out[N];

void rec (ll nn){
    if (vis[nn]) return;
    vis[nn]=1;
    if (nn==n) return; 
    if (!f[nn]){
        dp[nn]=-1;
        return;
    }
    ll mx=0;
    for (auto [e,w]:g[nn]){
        if (!vis[e]) rec(e);
        dp[nn]=min(dp[nn],dp[e]+1);
    }
    for (auto e:g2[nn]){
        mx=max(mx,dp[e]);
    }
    dp[nn]=min(dp[nn],mx);
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll m;
    cin >> n >> m;
    for (ll i=1;i<=n;i++) dis[i]=1e18,dp[i]=1e18;
    while (m--){
        ll u,v,w;
        cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        rg[v].emplace_back(u,w);
    }
    pq.emplace(0,n);
    while (!pq.empty()){
        auto [nd,nn]=pq.top(); pq.pop();
        if (dis[nn]<nd) continue;
        dis[nn]=nd;
        f[nn]=1;
        for (auto [xn,xw]:rg[nn]){
            if (dis[xn]>nd+xw){
                dis[xn]=nd+xw;
                pq.emplace(dis[xn],xn);
            }
        }
    }
    if (!f[1]){
        cout << "-1";
        return 0;
    }
    for (ll i=1;i<=n;i++){
        for (auto [xn,xw]:g[i]) {
            if (dis[i]==dis[xn]+xw) {
                g2[i].emplace_back(xn);
                rg2[xn].emplace_back(i);
                out[i]++;
            }
            // cout << i << " => " << dis[i] << ' ' << dis[xn]+xw << '\n';
        }
    }
    // rec(1);
    vector<ll> bn;
    for (int i=-1;!vis[1] && i<n;i++){
        if (i==-1){
            for (int i=1;i<n;i++){
                if (!f[i]){
                    q.emplace(i);
                }
            }
        }
        else{
            for (auto nn:bn){
                for (auto [e,w]:rg[nn]){
                    if (vis[e] || e==n) continue;
                    q.emplace(e);
                }
            }
        }
        vector<ll> tmp;
        while (!q.empty()){
            auto nn=q.front(); q.pop();
            if (vis[nn]) continue;
            vis[nn]=1;
            dp[nn]=i;
            tmp.emplace_back(nn);
            // cout << " => " << nn << ' ' << dp[nn] << '\n';
            for (auto e:rg2[nn]){
                if (vis[e] || e==n) continue;
                out[e]--;
                if (!out[e]){
                    q.emplace(e);
                }
            }
        }
        swap(bn,tmp);
    }
    // for (ll i=1;i<=n;i++) cout << i << " = " << dp[i] << '\n';
    cout << min(dp[1],n);
}