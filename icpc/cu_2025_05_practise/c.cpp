#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=1e3+5;
vector<int> g[N];
ll c[N],deg[N];
bool f[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> c[i];
    while (m--){
        int u,v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        deg[u]++;
        deg[v]++;
    }
    ll sum=0;
    for (int i=1;i<=n;i++){
        sum+=deg[i]*c[i];
    }
    vector<pair<ll,ll>> v;
    for (int i=1;i<=n;i++) v.emplace_back(c[i],i);
    sort(v.begin(),v.end());
    for (int i=n-1;i>=0;i--){
        auto [nc,nn]=v[i];
        sum-=nc*deg[nn];
        // cout << " => " << nc << ' ' << deg[nn] << '\n';
        for (auto e:g[nn]){
            if (!f[e]) deg[e]--;
        }
        f[nn]=1;
    }
    cout << sum;
}