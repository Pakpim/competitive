#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N=1e5+5;
bool f[N];
ll m[N],dp[N];
vector<ll> p;

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    for (ll i=1;i<N;i++) m[i]=1;
    for (ll i=2;i<N;i++){
        if (f[i]) continue;
        p.emplace_back(i);
        for (ll j=i;j<N;j+=i){
            f[j]=1;
            m[j]*=-1;
        }
    }
    for (auto e:p){
        for (ll i=e*e;i<N;i+=e*e) m[i]=0;
    }
    ll n;
    cin >> n;
    for (ll i=0;i<n;i++){
        ll x;
        cin >> x;
        
        
    }
}