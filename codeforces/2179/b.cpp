#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5;

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll sum=0, ans=1e18;
    for (auto &e:v) cin >> e;
    for (int i=1;i<n;i++) sum+=abs(v[i-1]-v[i]);
    for (int i=1;i<n-1;i++){
        ll nv=sum;
        nv-=abs(v[i]-v[i+1])+abs(v[i-1]-v[i]);
        nv+=abs(v[i-1]-v[i+1]);
        ans=min(ans,nv);
    }
    ans =min(ans,sum-abs(v[0]-v[1]));
    ans =min(ans,sum-abs(v[n-1]-v[n-2]));
    cout << ans << '\n';
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}