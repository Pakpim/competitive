#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=5e5+5;
ll a[N],b[N],qs[N],pm[N],sm[N];
map<ll,ll> cnt;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,ans=1e18;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];
    for (int i=1;i<=n;i++) qs[i]=qs[i-1]+b[i];
    pm[0]=-1e18; sm[n+1]=-1e18;
    for (int i=1;i<=n;i++) pm[i]=max(pm[i-1],a[i]-qs[i-1]);
    for (int i=n;i>0;i--) sm[i]=max(sm[i+1],a[i]-qs[i-1]);
    for (int i=1;i<=n;i++){
        ll nv=max(sm[i]+qs[i-1],pm[i-1]-qs[n]+qs[i-1]);
        // cout << i << " => " << nv << ' ' << sm[i]+qs[i-1] << ' ' <<pm[i-1]-qs[n]+qs[i-1] << '\n';
        ans=min(ans,nv);
    }
    cout << ans;
}