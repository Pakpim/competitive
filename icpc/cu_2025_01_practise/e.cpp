#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N=2005;
vector<ll> g[N];
ll p[N],mx;

void dfs (ll nn,ll nh){
    for (auto e:g[nn]) dfs(e,nh+1);
    mx=max(mx,nh);
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> p[i];
        if (p[i]==-1) p[i]=0;
        g[p[i]].emplace_back(i);
    }
    dfs(0,0);
    cout << mx;
}