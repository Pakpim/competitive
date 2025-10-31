#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll a[3],ans=0;
    cin >> a[0] >> a[1] >> a[2];
    for (ll i=0;i<=min({2ll,a[0],a[1],a[2]});i++){
        ans = max(ans,i + (a[0]-i)/3 + (a[1]-i)/3 + (a[2]-i)/3);
    }
    cout << ans;
}