#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,a;
    cin >> n >> a;
    ll mx=-1e18, sum=0;
    bool f=0;
    for (int i=1;i<n;i++){
        ll x;
        cin >> x;
        if (x<0 && a+x>=0) mx=max(mx,x);
        if (x>=0) sum+=x, f=1;
    }
    if (f) cout << a+sum;
    else if (mx!=-1e18) cout << a+mx;
    else cout << "-1";
}