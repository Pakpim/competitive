#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5;
ll a[N],b[N],c[N];

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m,w;
    cin >> n >> m >> w;
    for (ll i=1;i<=n;i++) cin >> a[i];
    ll l=0, r=2e9, mid, ans=0;
    while (l<=r){
        mid=(l+r)/2;
        // cout << " ? " << l << ' ' << r << ' ' << mid << '\n';
        bool ok=1;
        int nm=m;
        for (int i=1;i<=n;i++) {
            b[i]=max(0ll, mid-a[i]);
            c[i]=0;
        }
        for (int i=1;i<=n;i++){
            c[i]+=c[i-1];
            if (c[i]>=b[i]) continue;
            int nv=b[i]-c[i];
            if (nm<nv) {
                ok=0;
                break;
            }
            nm-=nv;
            c[i]+=nv;
            c[i+w]-=nv;
        }
        if (ok){
            ans=max(ans,mid);
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout << ans;
}