#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5;
ll a[N],b[N];
map<ll,ll> cnt;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,mx=-1;
    cin >> n;
    for (ll i=1;i<=n;i++) cin >> a[i];
    for (ll i=1;i<=n;i++) cin >> b[i];
    cnt[a[1]]++;
    cnt[a[2]]++;
    cnt[b[2]]++;
    for (ll i=3;i<=n;i++){
        cnt[a[i]]++;
        cnt[b[i]]++;
        a[i]=max(a[i],a[i-1]);
        b[i]=max(b[i],b[i-1]);
    }
    for (ll i=2;i<=n;i++){
        if (a[i]<=mx) continue;
        mx=a[i];
        ll ti=upper_bound(b+2,b+n+1,a[i])-b;
        ll tj=upper_bound(a+i,a+n+1,a[i])-a;
        ll nv=(ti-2)*(tj-i);
        // cout << " a: " << i << ' ' << a[i] << " => " << ti << ' ' << tj << ' ' << nv << '\n';
        cnt[a[i]]+=nv;
    }
    mx=-1;
    for (ll i=2;i<=n;i++){
        if (b[i]<=mx) continue;
        mx=b[i];
        ll ti=upper_bound(b+i,b+n+1,b[i])-b;
        ll tj=lower_bound(a+2,a+n+1,b[i])-a;
        ll nv=(ti-i)*(tj-2);
        // cout << " b: " << i << ' ' << b[i] << " => " << ti << ' ' << tj << ' ' << nv << '\n';
        cnt[b[i]]+=nv;
    }
    pair<ll,ll> ans={-1,-1};
    for (auto [k,v]:cnt) {
        ans=max(ans,{v,k});
    }
    cout << ans.second << ' ' << ans.first;
}