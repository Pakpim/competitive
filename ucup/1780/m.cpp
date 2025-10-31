#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,a,b;
    cin >> n >> a >> b;
    ll sum=0;
    for (ll i=1;i<=n;i++){
        ll nv=(n-i+1)*(n-i+2)/2;
        if (i*2<=n) nv+=(n-i*2+1)*(n-i*2+2)/2;
        sum+=nv;
    }
    sum-= b*(a-b+1);
    for (ll i=a+1;i<=n;i++){
        ll sz=i-a;
        ll l=sz+max(0ll,b-sz);
        ll r=min(a,b+sz-1);
        sum-= r-l+1;
    }
    cout << sum;
}