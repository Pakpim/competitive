#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=500005;
ll sum[N],sum2[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,mn=1e18,mn2=1e18,tg;
    cin >> n;
    vector<pair<ll,ll>> v(n);
    for (int i=1;i<=n;i++) cin >> v[i-1].second;
    for (int i=1;i<=n;i++) cin >> v[i-1].first;
    sort(v.begin(),v.end());
    for (int i=n;i>0;i--) sum[i]=sum[i+1]+v[i-1].first-1;
    for (int i=1;i<n;i++) sum2[i]=sum2[i-1]+v[i-1].first+v[i-1].second-1;
    for (int i=1;i<=n;i++) mn2=min(mn2,v[i-1].second);
    for (int i=1;i<=n;i++){
        auto [a,b]=v[i-1];
        if (a>mn2) continue;
        ll nv=sum2[i-1]+sum[i+1]-(n-1)*(a-1);
        // cout << a << ' ' << sum[i+1] << ' ' << sum2[i-1] << ' ' << (n-1)*(a-1) << '\n';
        if (mn>nv){
            mn=nv;
            tg=a;
        }
    }
    cout << tg << ' ' << mn;
}