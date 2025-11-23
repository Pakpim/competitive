#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using pll=pair<ll,ll>;
const ll N=1e5+5;

void solve(){
    ll n;
    bool ok=1;
    cin >> n;
    vector<int> v;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        v.emplace_back(a);
    }
    sort(v.begin(),v.end());
    for (int i=0;i<n-1;i++){
        if ((i&1)==0) continue;
        if (v[i]!=v[i+1]) ok=0;
        // cout << v[i] << ' ' <<  v[i+1] << ' ' << ok << '\n';
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        solve();
    }
}