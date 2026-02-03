#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,v;
    cin >> n >> v;
    ll d=n-v, sum=n, nn=n;
    for (ll i=0;i<64;i++){
        if (d>>i&1){
            nn-=1ll<<i;
            sum+=nn;
        }
    }
    cout << sum;
}