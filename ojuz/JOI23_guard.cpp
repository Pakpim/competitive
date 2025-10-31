#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=200005;
vector<ll> g[N];
ll sum=0,s[N],ar[N];


int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    for (int i=1;i<=n;i++) cin >> s[i];
    while (m--){
        int u,v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    cout << sum;
}