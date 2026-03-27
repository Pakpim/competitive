#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=500*500+5;
ll cnt[N], ps[N], ss[N];

void solve(){
    ll n,m,a,b;
    cin >> n >> m >> a >> b;
    for (int i=0;i<=n*m;i++) cnt[i]=0;
    for (ll i=0;i<n*m;i++){
        ll c;
        cin >> c;
        cnt[c]++;
    }
    sort(cnt+1,cnt+n*m+1);
    ll ans=1e18;
    for (ll i=1;i<=n*m;i++) ps[i]=cnt[i]*a+ps[i-1];
    ss[n*m+1]=0;
    ans=ps[n*m];
    for (ll i=n*m, j=1;i>0 && cnt[i]>0;i--, j++){
        ss[i]=cnt[i]*b*(j-1) + cnt[0]*b + ss[i+1];
        ll nv=ps[i-1]+ss[i];
        ans=min(ans,nv);
        // cout << i << ' ' << cnt[i] << ' ' << (m*n-i) << " => " << nv << ' ' << ps[i-1] << ' ' << ss[i] << ' ' << cnt[0] << ' ' << b << ' ' << (n*m-i+1) << '\n';
    }
    cout << ans << '\n';
}

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        solve();
    }
}