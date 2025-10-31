#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ti=tuple<ll,ll,ll>;
const ll N=1e5+5;
ll x[N],h[N];
stack<pair<ll,ll>> l,r;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    ti mx={-1e9,-1e9,-1e9};
    cin >> n;
    for (ll i=1;i<=n;i++) cin >> x[i] >> h[i];
    for (ll i=1;i<=n;i++){
        ll v=1;
        while (!l.empty() && l.top().first>x[i]-h[i]) v+=l.top().second,l.pop();
        l.emplace(x[i],v);
        ti t={v,-i,-'L'};
        mx=max(mx,t);
    }
    for (ll i=n;i>0;i--){
        ll v=1;
        while (!r.empty() && r.top().first<x[i]+h[i]) v+=r.top().second,r.pop();
        r.emplace(x[i],v);
        ti t={v,-i,-'R'};
        mx=max(mx,t);
    }
    auto [nv,ni,nd]=mx;
    cout << -ni << ' ' << char(-nd);
}