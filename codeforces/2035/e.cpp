#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using db=double;
ll x,y,z,k;

ll cal2 (ll a,ll b,ll h){
    ll ph=h/a+(h%a!=0);
    if (ph-b>k) return 1e18;
    return (ph-b)*x+y*a;
}

ll cal (ll a){
    ll re=a*x;
    ll h=z-k*a*(a+1)/2;
    ll l=2,r=h/k*a+(h%(k*a)!=0),mid;
    while (l<=r){
        mid=(l+r)/2;
        if (cal2(mid-1,k*a,h)==1e18){
            l=mid+1;
            continue;
        }
    }
    return re;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        cin >> x >> y >> z >> k;
        ll ans=1e18;
        db tmp=sqrt(2*db(z)/db(k));
        for (int i=0;i<=tmp;i++){
            ans=min(ans,cal(i));
            cout << " => " << i << ' ' << cal(i) << '\n';
        }
        cout << ans << '\n';
    }
}