#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e6+5;
vector<ll> g[N];
bool vis[N];

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m;
    cin >> n >> m;
    while (m--){
        ll u,v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    ll ans=0;
    vector<ll> v;
    for (ll i=1;i<=n;i++){
        if (vis[i]) continue;
        ll nv=0, ne=0;
        queue<ll> q;
        q.emplace(i);
        while (!q.empty()){
            ll nn=q.front(); q.pop();
            if (vis[nn]) continue;
            vis[nn]=1;
            nv++;
            ne+=g[nn].size();
            for (auto e:g[nn]) q.emplace(e);
        }
        // cout << " ? " << nv << ' ' << ne << ' ' << (nv*(nv-1) - ne)/2 << '\n';
        v.emplace_back(nv);
        ans+=(nv*(nv-1) - ne)/2;
    }
    sort(v.begin(),v.end());
    if (!ans) ans+=v[0]*v[1];
    cout << ans;
}