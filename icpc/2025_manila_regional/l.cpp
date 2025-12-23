#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    map<ll,ll> mp[N];
    while (k--){
        ll r,c,v;
        cin >> r >> c >> v;
        mp[r][c]=v;
    }
    cin >> k;
    ll sum=0;
    while (k--){
        ll r,c,v;
        cin >> r >> c >> v;
        if (mp[c].count(r)){
            sum+=v*mp[c][r];
            sum%=1006903069;
        }
    }
    sum%=1006903069;
    cout << sum;
}