#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=(1<<20)+5;
vector<ll> v;
ll n,k,a,b;

ll cal (ll l,ll r){
    ll nv;
    ll sz=upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l);
    if (sz) nv=(sz)*b*(r-l+1);
    else nv=a;
    if (l==r){
        return nv;
    }
    if (sz){
        ll mid=(l+r)/2;
        ll vl=cal(l,mid),vr=cal(mid+1,r);
        nv=min(nv,vl+vr);
    }
    // cout << l << ' ' << r << " => " << nv << '\n';
    return nv;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> a >> b;
    n=(1ll<<n);
    while (k--){
        ll p;
        cin >> p;
        v.emplace_back(p);
    }
    sort(v.begin(),v.end());
    cout << cal(1,n);
}