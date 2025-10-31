#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5;
vector<ll> v[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,d;
    cin >> n >> d;
    for (int i=1;i<=n;i++){
        ll a;
        cin >> a;
        v[a].emplace_back(i);
    }
    for (int i=0;i<=n;i++){
        bool ok=1;
        ll tx=-d, tn=tx;
        for (auto e:v[i]){
            ll xx,xn;
            if (tn+d<e) xx=e+d-1;
            else if (tx>=e) xx=tx;
            else ok=0;
            if (tn<=e && tx>=e) xn=e;
            else if (tn+d<e) xn=max(e,tn+d+d);
            else if (tx>=e && tn>=e) xn=tn;
            else ok=0;
            tn=xn;
            tx=xx;
            // cout << i <<  " = " << tn << ' ' << tx << ' ' << ok << '\n';
        }
        if (ok){
            cout << i;
            return 0;
        }
    }
    cout << n+1;
}