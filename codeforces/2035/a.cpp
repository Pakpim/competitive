#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll n,m,r,c;
        cin >> n >> m >> r >> c;
        ll ans=(n-r)*(m-1)+(n-r)*(1+m-1)+(m-c);
        cout << ans << '\n';
    }
}