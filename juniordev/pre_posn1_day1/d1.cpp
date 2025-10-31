#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=5e5+5;
ll x[N],a1[N],a2[N],sum;
vector <pair<ll,ll>> v,v2;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n;
    for (int i=0;i<n;i++) cin >> x[i];
    cin >> m;
    for (int i=0;i<m;i++){
        int t,d;
        cin >> t >> d;
        v.emplace_back(d,t);
    }
    sort(v.begin(),v.end());
    v2.emplace_back(v[0].first,v[0].second);
    for (int i=1;i<v.size();i++){
        if (v2.back().first<v[i].first && v2.back().second>=v[i].second) v2.emplace_back(v[i].first,v[i].second);
    }
    deque<pair<ll,ll>> dq;
    for (int i=n-1;i>=0;i--){
        if (dq.empty()){
            a1[i]=0;
        }
        else{
            auto it=lower_bound(dq.begin(),dq.end(),make_pair(x[i],-1ll));
            if (it==dq.begin()) a1[i]=0;
            else {
                it--;
                a1[i]=it->second-i;
            }
        }
        while (!dq.empty() && dq.back().first>=x[i]) dq.pop_back();
        dq.emplace_back(x[i],i);
        sum+=a1[i];
    }
    // for (auto [a,b]:v2){
    //     cout << " => " << a << ' ' << b << '\n';
    // }
    for (int i=0;i<n;i++){
        auto it=upper_bound(v2.begin(),v2.end(),make_pair(x[i],ll(1e9)));
        it--;
        // cout << x[i] << ' ' << it->first << ' ' << it->second << '\n';
        a2[i]=it->second;
        sum+=a2[i];
    }
    for (int i=0;i<n;i++) cout << a1[i] << ' ';
    cout << '\n';
    for (int i=0;i<n;i++) cout << a2[i] << ' ';
    cout << '\n' << sum << '\n';
}