#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=5e5+5;
ll sf[N],sb[N],cf[N],cb[N];
pair<ll,ll> ar[2][N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    for (ll i=1;i<=n;i++){
        cin >> ar[0][i].first >> ar[1][i].first >> ar[0][i].second;
        ar[1][i].second=ar[0][i].second;
    }
    ll ans=0;
    for (ll t=0;t<2;t++){
        ll mn=1e18;
        sort(ar[t]+1,ar[t]+n+1);
        for (int i=n;i>0;i--){
            sb[i]=sb[i+1]+cb[i+1]*(ar[t][i+1].first-ar[t][i].first);
            cb[i]=cb[i+1]+ar[t][i].second;
        }
        for (int i=1;i<=n;i++){
            sf[i]=sf[i-1]+cf[i-1]*(ar[t][i].first-ar[t][i-1].first);
            cf[i]=cf[i-1]+ar[t][i].second;
            mn=min(mn,sf[i]+sb[i+1]+cb[i+1]*(ar[t][i+1].first-ar[t][i].first));
        }
        ans+=mn;
    }
    cout << ans;
}