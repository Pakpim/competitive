#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e6+5;
vector<int> g[N];
bool vis[N];
ll c[N];

ll bp(ll a, ll b, ll p){
    ll re=1;
    while (b){
        if (b&1) re=(re*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return re;
}

bool cal (int st){
    queue<pair<int,int>> q;
    q.emplace(st,0);
    while (!q.empty()){
        auto [nn,nc]=q.front(); q.pop();
        if (vis[nn]){
            if (c[nn]!=nc) return 0;
            continue;
        }
        vis[nn]=1;
        c[nn]=nc;
        for (auto e:g[nn]) q.emplace(e, nc^1);
    }
    return 1;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m,p;
    bool ok=1;
    cin >> n >> m >> p;
    ll ans=bp(2,p-2,p);
    while (m--){
        ll u,v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for (int i=1;i<=n;i++){
        if (vis[i]) continue;
        bool nv=cal(i);
        if (nv) ans=(ans*2)%p;
        else ok=0;
    }
    if (!ok){
        cout << "impossible";
        return 0;
    }
    ans=(ans+1)%p;
    cout << ans;
}