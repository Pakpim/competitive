#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using pll=pair<ll,ll>;
const ll N=2e5+5;
ll a[4][N],pmn[N],pmx[N],smn[N],smx[N];

void solve(){
    ll n;
    cin >> n;
    vector<pll> v;
    for (ll i=1;i<=2;i++) for (ll j=1;j<=n;j++) {
        cin >> a[i][j];
    }
    pmn[0]=1e9; pmx[0]=0;
    for (ll i=1;i<=n;i++){
        pmn[i]=min(pmn[i-1],a[1][i]);
        pmx[i]=max(pmx[i-1],a[1][i]);
    }
    smn[n+1]=1e9; smx[n+1]=0;
    for (ll i=n;i>0;i--){
        smn[i]=min(smn[i+1],a[2][i]);
        smx[i]=max(smx[i+1],a[2][i]);
    }
    ll cnt=0;
    for (ll i=1;i<=n;i++){
        ll l=min(pmn[i],smn[i]), r=max(pmx[i],smx[i]);
        v.emplace_back(l,r);
    }
    sort(v.begin(),v.end());
    vector<pll> v2;
    for (auto [l,r]:v){
        while (!v2.empty() && v2.back().second>=r){
            v2.pop_back();
        }
        v2.emplace_back(l,r);
    }
    ll tl=0;
    for (auto [l,r]:v2){
        cnt+=(l-tl)*(2*n-r+1);
        tl=l;
    }
    cout << cnt << '\n';
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        solve();
    }
}