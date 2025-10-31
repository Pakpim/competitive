#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5;
ll a[N],b[N];

void solve (){
    int n,k;
    ll ans=1e18,sum=0;
    cin >> n >> k;
    vector<tuple<ll,ll>> v;
    priority_queue<ll> pq;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> b[i];
    for (int i=0;i<n;i++) v.emplace_back(a[i],b[i]);
    sort(v.begin(),v.end());
    for (int i=0;i<k-1;i++){
        auto [na,nb]=v[i];
        sum+=nb;
        pq.emplace(nb);
    }
    for (int i=k-1;i<n;i++){
        auto [na,nb]=v[i];
        sum+=nb;
        pq.emplace(nb);
        // cout << " => " << na << ' ' << sum << '\n';
        ans=min(ans,sum*na);
        sum-=pq.top();
        pq.pop();
    }
    cout << ans << '\n';
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}