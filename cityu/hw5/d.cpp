#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=505;
vector<ll> g[N*2];
ll lv[N*2],cur[N*2], id[N],cnt, n,m,r,t,k, a[N][N], b[N];
vector<ll> fr,to,cap;

bool bfs(ll st, ll tg){
    for (ll i=0;i<=n+m+1;i++) lv[i]=0;
    queue<tuple<ll,ll>> q;
    q.emplace(st,1);
    while (!q.empty()){
        auto [nn,nd]=q.front();
        q.pop();
        if (lv[nn]) continue;
        lv[nn]=nd;
        for (auto e:g[nn]) {
            if (!cap[e]) continue;
            q.emplace(to[e], nd+1);
        }
    }
    return lv[tg];
}

ll dfs(ll nn,ll tg,ll np,ll nt){
    if (!np) return 0;
    if (nn==tg) return np;
    while (cur[nn]<g[nn].size()){
        ll e=g[nn][cur[nn]];
        cur[nn]++;
        if (cap[e]<1 || lv[to[e]]!=lv[nn]+1) continue;
        ll xp=dfs(to[e],tg, min(np, cap[e]),nt);
        if (!xp) continue;
        cap[e]-=xp;
        cap[e^1]+=xp;
        if (to[e]<=n && nn>n) a[to[e]][nn-n]=-1;
        if (nn<=n && to[e]>n) a[nn][to[e]-n]=nt;
        // cout << " ? " << nn << ' ' << to[e] << ' ' << xp << ' ';
        // if (nn<=n && to[e]>n) cout << a[nn][to[e]-n] << '\n';
        // else cout << '\n';
        return xp;
    }
    return 0;
}
void add (ll u,ll v){
    fr.emplace_back(u); to.emplace_back(v), cap.emplace_back(1);
    g[u].emplace_back(cnt++);
    fr.emplace_back(v); to.emplace_back(u), cap.emplace_back(0);
    g[v].emplace_back(cnt++);
}

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> r >> t >> k;
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) a[i][j]=-1;
    t=t/r;
    for (ll i=0;i<k;i++){
        ll u,v;
        cin >> u >> v;
        add(u,v+n);
    }
    ll tg=n+m+1;
    ll sum=0,bf=0, nv=0;
    for (ll i=1;i<=n;i++) add(0,i), id[i]=cnt-2;
    for (ll i=n+1;i<=n+m;i++) add(i,tg);
    for (ll i=1;i<=t;i++){
        while (bfs(0,tg)){
            for (ll i=0;i<=tg;i++) cur[i]=0;
            while (1){
                ll nf=dfs(0,tg,1e9,i-1);
                if (!nf) break;
                nv+=nf;
            }
        }
        // cout << '\n';
        if (!(nv-bf)) break;
        sum+=i*(nv-bf);
        bf=nv;
        for (ll i=1;i<=n;i++) cap[id[i]]++;
    }
    cout << nv << ' ' << sum*r << '\n';
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j]==-1) continue;
            cout << i << ' ' << j << ' ' << b[i]*r << '\n';
            b[i]++;
        }
    }
}

/*
1 5 3 8 5
1 1
1 2
1 3
1 4
1 5
*/