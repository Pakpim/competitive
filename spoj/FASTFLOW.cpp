#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=5005, M=30005*2, inf=1e18;
vector<ll> g[N];
ll n,m,lv[N],fr[M],to[M],car[M], cur[N];
map<ll,ll> tmp[N];

bool bfs(){
    for (int i=1;i<=n;i++) lv[i]=0;
    queue<tuple<ll,ll>> q;
    q.emplace(1,1);
    while (!q.empty()){
        auto [nn,nd]=q.front();
        q.pop();
        if (lv[nn]) continue;
        lv[nn]=nd;
        for (auto e:g[nn]) {
            if (car[e]<1) continue;
            q.emplace(to[e], nd+1);
        }
    }
    // cout << "bfs : ";
    // for (int i=1;i<=n;i++) cout << lv[i] << ' ';
    // cout << '\n';
    return lv[n];
}

ll dfs(ll nn,ll np){
    if (!np) return 0;
    if (nn==n) return np;
    while (cur[nn]<g[nn].size()){
        ll e=g[nn][cur[nn]];
        cur[nn]++;
        // cout << " ! " << nn << ' ' << to[e] << ' ' << car[e] << ' ' << lv[nn] << ' ' << lv[to[e]] << '\n';
        if (car[e]<1 || lv[to[e]]!=lv[nn]+1) continue;
        ll xp=dfs(to[e], min(np, car[e]));
        if (!xp) continue;
        // cout << " ? " << nn << ' ' << to[e] << ' ' << xp << '\n';
        car[e]-=xp;
        car[e^1]+=xp;
        return xp;
    }
    return 0;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i=0;i<m;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        if (u==v) continue;
        if (u>v) swap(u,v);
        tmp[u][v]+=w;
    }
    int k=0;
    for (int u=1;u<=n;u++){
        for (int v=u+1;v<=n;v++){
            if (tmp[u].count(v)==0) continue;
            fr[k]=u; to[k]=v; car[k]=tmp[u][v];
            fr[k+1]=v; to[k+1]=u; car[k+1]=tmp[u][v];
            g[u].emplace_back(k);
            g[v].emplace_back(k+1);
            k+=2;
        }
    }
    ll sum=0;
    // ll cnt=0;
    while (bfs()){
        for (int i=1;i<=n;i++) cur[i]=0;
        while (true){
            ll nf=dfs(1,inf);
            if (!nf) break;
            sum+=nf;  
        }
        // for (int i=0;i<k;i++) cout << cnt << " : " << fr[i] << ' ' << to[i] << ' ' << car[i] << '\n';
        // cout << '\n';
        // if (cnt>n+5) break;
        // cnt++;
    }
    cout << sum;
}