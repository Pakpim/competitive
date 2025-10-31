#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5;
ll n,k,sum;

pair<ll,ll> rec(ll l,ll r){
    if (r-l+1<k) return {0,0};
    ll mid=(l+r)/2;
    if ((r-l+1)&1) {
        auto [cnt,ans]=rec(l,mid-1);
        return {cnt*2+1,ans*2+cnt*mid+mid};
    }
    else{
        auto [cnt,ans]=rec(l,mid);
        return {cnt*2,ans*2+cnt*mid};
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        cin >> n >> k;
        auto [cnt,ans]=rec(1,n);
        cout << ans << '\n';
    }
}