#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5;
ll a[N],b[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    for (ll i=0;i<n;i++){
        cin >> a[i];
    }
    for (ll i=0;i<n;i++){
        cin >> b[i];
    }
    sort(a,a+n);
    sort(b,b+n,greater<ll>());
    ll mn=2e9+5,mx=0;
    for (ll i=0;i<n;i++){
        ll nv=a[i]+b[i];
        mn=min(mn,nv);
        mx=max(mx,nv);
    }
    cout << mx-mn;
}