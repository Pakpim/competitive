#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N = 1000005;
ll a[N],b[N],dp[N],tmp[N];
vector <pair<ll,ll>> v;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m;
    cin >> n >> m;
    for (ll i=0;i<n;i++) cin >> a[i];
    for (ll i=0;i<n;i++) cin >> b[i];
    for (ll i=0;i<N;i++) tmp[i]=1e9;
    for (ll i=0;i<n;i++) tmp[a[i]-b[i]]=min(tmp[a[i]-b[i]],a[i]);
    for (ll i=0;i<N;i++) {
        if (tmp[i]==1e9 || (!v.empty() && tmp[i]>=v.back().second)) continue;
        v.emplace_back(i,tmp[i]);
    }
    for (ll i=v.size()-1;i>0;i--){
        for (ll j=v[i].second;j<v[i-1].second;j++){
            ll k=(j-v[i].second)/v[i].first +1;
            dp[j]=k+dp[j-k*v[i].first];
        }
    }
    ll sum=0;
    while (m--){
        ll c;
        cin >> c;
        if (c>=v[0].second){
            sum+=(c-v[0].second)/v[0].first+1;
            c-=((c-v[0].second)/v[0].first+1)*v[0].first;
        }
        sum+=dp[c];
    }
    cout << sum*2;
    
}