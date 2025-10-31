#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using db=double;
using pll=pair<ll,ll>;
const ll N=2e5+5;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,r;
    cin >> n >> r;
    while (n--){
        ll d,a;
        cin >> d >> a;
        if ((d==1 && r>=1600 && r<=2799) || (d==2 && r>=1200 && r<=2399)) r+=a;
    }
    cout << r;
}