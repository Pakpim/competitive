#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=404;
vector<ll> g[N];
ll lv[N],cur[N], id[N],cnt, n,m,r,t,k;
vector<ll> fr,to,cap;
bool vis[N],a[N][N];

bool bfs(ll st, ll tg){
    for (ll i=0;i<=n*2+1;i++) lv[i]=0;
    queue<tuple<ll,ll>> q;
    q.emplace(st,1);
    while (!q.empty()){
        auto [nn,nd]=q.front();
        q.pop();
        if (lv[nn]) continue;
        lv[nn]=nd;
        // cout << " ? " << nn << ' ' << nd << '\n';
        for (auto e:g[nn]) {
            if (!cap[e]) continue;
            q.emplace(to[e], nd+1);
        }
    }
    return lv[tg];
}

ll dfs(ll nn,ll tg,ll np){
    if (!np) return 0;
    if (nn==tg) return np;
    while (cur[nn]<g[nn].size()){
        ll e=g[nn][cur[nn]];
        cur[nn]++;
        if (cap[e]<1 || lv[to[e]]!=lv[nn]+1) continue;
        ll xp=dfs(to[e],tg, min(np, cap[e]));
        if (!xp) continue;
        cap[e]-=xp;
        cap[e^1]+=xp;
        if (to[e]>n && nn<=n) a[to[e]-n][nn]=0;
        if (nn>n && to[e]<=n) a[nn-n][to[e]]=1;
        // cout << " ? " << nn << ' ' << to[e] << ' ' << xp << ' ';
        // if (nn>n && to[e]<=n) cout << a[nn-n][to[e]] << '\n';
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
    cin >> n >> m;
    while (m--){
        ll u,v;
        cin >> u >> v;
        add(u+n,v);
    }
    ll tg=n*2+1;
    for (ll i=n+1;i<=n+n;i++) add(0,i);
    for (ll i=1;i<=n;i++) add(i,tg);
    int sum=0;
    while (bfs(0,tg)){
        for (ll i=0;i<=tg;i++) cur[i]=0;
        while (1){
            ll nf=dfs(0,tg,1e9);
            if (!nf) break;
            sum+=nf;
        }
        // cout << " => " << sum << '\n';
        // for (int i=0;i<=n*2+1;i++){
        //     cout << i << " : ";
        //     for (auto e:g[i]) if (cap[e]) cout << "(" << fr[e] << ' ' << to[e] << ") ";
        //     cout << '\n';
        // }
        // cout << '\n';
        // for (int i=1;i<=n;i++) {
        //     for (int j=1;j<=n;j++) cout << a[i][j] << ' ';
        //     cout << '\n';
        // }
        // cout << "-----------------------------\n";
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        if (vis[i]) continue;
        bool ok=1;
        for (int j=1;j<=n;j++) ok&=(!a[j][i]);
        if (!ok) continue;
        ans++;
        int nn=i;
        while (1){
            cout << nn << ' ';
            vis[nn]=1;
            bool f=0;
            for (int j=1;j<=n;j++){
                if (a[nn][j]){
                    nn=j;
                    f=1;
                    break;
                }
            }
            if (!f) break;
        }
        cout << '\n';
    }
    cout << ans;
}

/*
10 9
1 2
1 3
1 4
2 5
3 6
4 7
5 8
6 8
7 8
*/