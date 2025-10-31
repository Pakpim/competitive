#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=200005;
ll a[N],b[N],pa[N],pb[N],sa[N],sb[N];

pair<ll,ll> cal(ll l,ll r){
    if (l>r) return {-1,-1};
    if (l==r){
        ll ga=__gcd(b[l],pa[l-1]), gb=__gcd(a[l],pb[l-1]);
        ga=__gcd(ga,sa[l+1]); gb=__gcd(gb,sb[l+1]);
        return {ga+gb,1};
    }
    ll mid=(l+r)/2;
    auto [mx1,c1]=cal(l,mid);
    auto [mx2,c2]=cal(mid+1,r);
    ll mx=0,c3=0;
    if (mx1<mx2) mx=mx2,c3=c2;
    else if (mx1>mx2) mx=mx1,c3=c1;
    else mx=mx1,c3=c1+c2;
    map<pair<ll,ll>,ll> ml,mr;
    ll ga=0,gb=0;
    for (int i=mid;i>=l;i--) {
        ga=__gcd(ga,b[i]);
        gb=__gcd(gb,a[i]);
        ml[{__gcd(ga,pa[i-1]),__gcd(gb,pb[i-1])}]++;
    }
    ga=0,gb=0;
    for (int i=mid+1;i<=r;i++) {
        ga=__gcd(ga,b[i]);
        gb=__gcd(gb,a[i]);
        mr[{__gcd(ga,sa[i+1]),__gcd(gb,sb[i+1])}]++;
    }
    for (auto [gl,cl]:ml){
        for (auto [gr,cr]:mr){
            ll na=__gcd(gl.first,gr.first), nb=__gcd(gl.second,gr.second);
            ll nv=na+nb;
            if (nv>mx){
                mx=nv;
                c3=0;
            }
            if (nv==mx) c3+=cl*cr;
        }
    }
    // cout << l << ' ' << r << " => " << mx << ' ' << c3 << '\n';
    return {mx,c3};
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=n;i++) cin >> b[i];
        pa[0]=pb[0]=0; sa[n+1]=sb[n+1]=0;
        for (int i=1;i<=n;i++) pa[i]=__gcd(a[i],pa[i-1]), pb[i]=__gcd(b[i],pb[i-1]);
        for (int i=n;i>=1;i--) sa[i]=__gcd(a[i],sa[i+1]), sb[i]=__gcd(b[i],sb[i+1]);
        auto [ans,cnt]=cal(1,n);
        cout << ans << ' ' << cnt << '\n';
    }
}

/*
1
2
18 13
15 20

1
2
13 14
5 8
*/