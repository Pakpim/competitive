#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5;
bool f[N];
vector<ll>p;

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    for (ll i=2;i<N;i++){
        if (f[i]) continue;
        p.emplace_back(i);
        for (ll j=i*2;j<N;j+=i) f[j]=1;
    }
    ll t;
    cin >> t;
    while (t--){
        ll a0,a1,b0,b1;
        cin >> a0 >> a1 >> b0 >> b1;
        ll v[4]={a0,a1,b0,b1}, ans=1;
        for (auto e:p){
            ll c[4]={0,0,0,0};
            for (int i=0;i<4;i++){
                while (v[i]%e==0){
                    c[i]++;
                    v[i]/=e;
                }
            }
            // if (c[0]+c[1]+c[2]+c[3]) cout << e << " = " << c[0] << ' ' << c[1] << ' ' << c[2] << ' ' << c[3] << '\n';
            if (c[0]>c[1] && c[2]<c[3] && c[3]!=c[1]) ans=0;
            if (c[0]==c[1] && c[2]==c[3]) {
                ans*=(c[3]-c[1]+1);
                // if (c[3]-c[1]) cout << " => " << c[3]-c[1]+1 << '\n';
            }
        }
        if (v[0]==v[1]==1 && v[2]==v[3] && v[2]>1) ans*=2;
        if (v[0]!=v[1] && v[2]!=v[3] && v[0]==v[3]) ans=0;
        cout << ans << '\n';
    }
}

/*
3
4 2 2 8
41 1 96 288
95 1 37 1776
*/