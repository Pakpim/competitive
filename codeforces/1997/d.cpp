#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=200005;
ll a[N],p[N],mn[N];
vector<ll> g[N];

ll dfs (int nn){
    for (auto e:g[nn]) dfs(e);
    mn[nn]=a[nn];
    if (!g[nn].empty()){
        ll tmp=1e9;
        for (auto e:g[nn]) tmp=min(tmp,mn[e]);
        if (a[nn]<tmp) mn[nn]=(a[nn]+tmp)/2;
        else mn[nn]=tmp;
        return tmp+a[nn];
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=2;i<=n;i++) cin >> p[i],g[p[i]].emplace_back(i);
        cout << dfs(1) << '\n';
        for (int i=1;i<=n;i++) g[i].clear();
    }
}