#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ti=tuple<ll,ll>;
using bt=bitset<10>;
const ll N=1e5;
ll a[N];
set<ll> s;
priority_queue<ti,vector<ti>,greater<ti>> pq;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,k;
    cin >> n >> k;
    for (ll i=0;i<n;i++) cin >> a[i];
    ll cnt=0;
    pq.emplace(0,0);
    while (!pq.empty()){
        auto [nv,nn]=pq.top();
        pq.pop();
        if (s.count(nn)) continue;
        s.emplace(nn);
        cnt++;
        cout << nv << ", ";
        // if (cnt==k){
        //     cout << nv;
        //     break;
        // }
        for (ll i=0;i<n;i++){
            if (!(nn>>i&1ll)) pq.emplace(nv+a[i],nn|(1ll<<i));
        }
    }
}