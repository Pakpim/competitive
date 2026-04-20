#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5;
int h[N],w[N], ans[N];

void solve(){
    int n;
    cin >> n;
    vector<tuple<int,int,int>> v, v2;
    for (int i=1;i<=n;i++){
        cin >> h[i] >> w[i];
        v.emplace_back(h[i],w[i],i);
        v.emplace_back(w[i],h[i],i);
        ans[i]=-1;
    }
    sort(v.begin(),v.end());
    for (auto [w,h,i]:v){
        if (v2.empty() || get<1>(v2.back())>h) v2.emplace_back(w,h,i);
    }
    for (int i=1;i<=n;i++){
        auto it = lower_bound(v2.begin(),v2.end(),make_tuple(h[i],0,0));
        if (it==v2.begin()) continue;
        it--;
        if (get<1>(*it)>=w[i]) continue;
        ans[i]=get<2>(*it);
    }
    for (int i=1;i<=n;i++) cout << ans[i] << ' ';
    cout << '\n';
}

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}