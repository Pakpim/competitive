#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using pll=pair<ll,ll>;
const ll N=4e5+5;
vector<pll> g[N],rg[N];
vector<ll> g2[N];
queue<ll> q;
queue<pll> q2;
priority_queue<pll,vector<pll>,greater<pll>> pq;
bool f[N],f2[N],f3[N];
ll cnt[N],dis[N],dp[N],n;

void rec (ll nn){
    if (f3[nn]) return;
    if(!f[nn]) {
        dp[nn]=-1;
        return;
    }
    if (nn==n) return; 
    f3[nn]=1;
    ll mx=0,tg=0;
    for (auto [e,w]:g[nn]) rec(e);
    for (auto [e,w]:g[nn]){
        if (!f[e]) {
            dp[nn]=0;
            // cout << nn << ' ' << dp[nn] << '\n';
            return;
        }
    }
    for (auto e:g2[nn]){
        if (mx<dp[e]){
            mx=dp[e];
            tg=e;
        }
    }
    for (auto e:g2[nn]){
        if (tg==e) dp[nn]=min(dp[nn],dp[e]);
        else dp[nn]=min(dp[nn],dp[e]+1);
    }
    for (auto [e,w]:g[nn]) dp[nn]=min(dp[nn],dp[e]+1);
    // cout << nn << " => " << dp[nn] << '\n';
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll m,mn=1e9;
    cin >> n >> m;
    for (ll i=1;i<=n;i++) cnt[i]=1e9,dis[i]=1e18,dp[i]=1e9;
    while (m--){
        ll u,v,w;
        cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        rg[v].emplace_back(u,w);
    }
    pq.emplace(0,n);
    vector<ll> ord;
    while (!pq.empty()){
        auto [nd,nn]=pq.top(); pq.pop();
        if (dis[nn]<nd) continue;
        ord.emplace_back(nn);
        for (auto [xn,xw]:rg[nn]){
            if (dis[xn]>nd+xw){
                dis[xn]=nd+xw;
                pq.emplace(dis[xn],xn);
            }
        }
    }
    if(dis[1]==1e18){
        cout << -1;
        exit(0);
    }
    q.emplace(n);
    while (!q.empty()){
        ll nn=q.front(); q.pop();
        if (f[nn]) continue;
        f[nn]=1;
        for (auto [xn,xw]:rg[nn]) q.emplace(xn);
    }
    for (ll i=1;i<=n;i++){
        for (auto [xn,xw]:g[i]) if (dis[i]==dis[xn]+xw) g2[i].emplace_back(xn);
    }
    rec(1);
    // q2.emplace(1,0);
    // while (!q2.empty()){
    //     auto [nn,nd]=q2.front(); q2.pop();
    //     if (f2[nn]) continue;
    //     f2[nn]=1;
    //     cnt[nn]=nd;
    //     if (nn==n) continue;
    //     for (auto [xn,xw]:g[nn]){
    //         q2.emplace(xn,nd+1);
    //     }
    // }
    // if (cnt[n]==1e9){
    //     cout << "-1";
    //     exit(0);
    // }
    // for (ll i=1;i<=n;i++){
    //     cout << i << " => " << f[i] << ' ' << f2[i] << ' ' << cnt[i] << '\n';
    //     if (!f[i] && f2[i]){
    //         mn=min(mn,cnt[i]-1);
    //     }
    // }
    cout << min(dp[1],n);
}