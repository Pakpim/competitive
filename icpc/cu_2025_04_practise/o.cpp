#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=30;
ll ca[N],cb[N],cc[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    string a,b,c;
    cin >> a >> b >> c;
    for (auto e:a) ca[e-'a']++;
    for (auto e:b) cb[e-'a']++;
    for (auto e:c) cc[e-'a']++;
    ll mx=0,tb=0,tc=0;
    for (ll i=0;i<=a.size();i++){
        bool ok=1;
        for (ll j=0;j<N;j++){
            if (ca[j]<cb[j]*i) ok=0;
        }
        if (!ok) continue;
        ll nv=1e9;
        for (ll j=0;j<N;j++){
            if (cc[j]!=0) nv = min(nv,(ca[j]-cb[j]*i)/cc[j]);
        }
        if (mx<i+nv){
            mx=i+nv;
            tb=i;
            tc=nv;
        }
    }
    for (ll i=0;i<tb;i++) cout<<b;
    for (ll i=0;i<tc;i++) cout<<c;
    for (ll i=0;i<N;i++){
        for (ll j=0;j<ca[i]-cb[i]*tb-cc[i]*tc;j++) cout<< char(i+'a');
    }
}