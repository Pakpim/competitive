#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=200005;
ll a[N];
deque<pair<ll,ll>> v;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        for (int i=0;i<n;i++) cin >> a[i];
        v.clear();
        v.emplace_back(a[0],1);
        for (int i=1;i<n;i++){
            if (v.back().first<a[i]) v.emplace_back(a[i],1);
            else if (v.back().first==a[i]) v.back().second++;
            else{
                ll nv = a[i],c1=1,c2=0;
                while (!v.empty() && nv-(c2!=0)<=v.back().first){
                    auto [bv,bc]=v.back();
                    v.pop_back();
                    ll tv=(nv*c1+(nv-1)*c2+bv*bc)/(c1+c2+bc);
                    ll tc=(nv*c1+(nv-1)*c2+bv*bc)%(c1+c2+bc);
                    if (!tc){
                        c1=c1+c2+bc;
                        nv=tv;
                        c2=0;
                    }
                    else{
                        c2=c1+c2+bc-tc;
                        c1=tc;
                        nv=tv+1;
                    }
                }
                if (c2) v.emplace_back(nv-1,c2);
                v.emplace_back(nv,c1);
            }
        }
        cout << v.back().first-v.front().first << '\n';
    }
}