#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N=4005;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,a,b,c,mx=0;
    cin >> n >> a >> b >> c;
    for (ll i=0;i*a<=n;i++){
        for (ll j=0;j*b<=n-i*a;j++){
            ll nn=n-a*i-b*j;
            if (nn%c==0){
                ll k=nn/c;
                mx=max(mx,i+j+k);
            }
        }
    }
    cout << mx;
}