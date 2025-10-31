#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll n,m;
        cin >> n >> m;
        vector<ll> a(n,0);
        ll mx=0;
        while (m--){
            ll u,v,w;
            cin >> u >> v >> w;
            u--;
            v--;
            ll bu=a[u],bv=a[v];
            a[u]=bv+w;
            a[v]=bu+w;
            mx=max({mx,a[u],a[v]});
        }
        cout << mx << '\n';
    }
}