#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5;
ll ar[N],w,n;

ll cal (ll l,ll r){
    ll nv=upper_bound(ar,ar+n,r)-lower_bound(ar,ar+n,l);
    if (!nv) return 0;
    if (r-l+1<3) return nv;
    ll u=(r-l+1)/3,v=(r-l+2)/3;
    ll a=cal(l,l+u-1),b=cal(l+u,l+u+v-1),c=cal(l+u+v,r);
    ll mn=min({a,b,c}),sum=a+b+c;
    return nv+sum-mn;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> w >> n;
    for (ll i=0;i<n;i++) cin >> ar[i];
    sort(ar,ar+n);
    cout << cal(1,w);
}