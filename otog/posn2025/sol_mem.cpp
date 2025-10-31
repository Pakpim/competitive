#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using vi=vector<bool>;
using ti=tuple<ll,vi>;
using bt=bitset<10>;
const ll N=1e5;
ll a[N];
set<vi> s;
priority_queue<ti,vector<ti>,greater<ti>> pq;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,k;
    cin >> n >> k;
    for (ll i=0;i<n;i++) cin >> a[i];
    ll cnt=0;
    vi st(n,0);
    pq.emplace(0,st);
    while (!pq.empty()){
        auto [nv,nn]=pq.top();
        pq.pop();
        if (s.count(nn)) continue;
        s.emplace(nn);
        cnt++;
        // cout << nv << ", ";
        if (cnt==k){
            cout << nv;
            break;
        }
        for (ll i=0;i<n;i++){
            if (!(nn[i])){
                vi xn=nn;
                xn[i]=1;
                pq.emplace(nv+a[i],xn);
            }
        }
    }
}