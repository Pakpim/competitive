#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t,M=998244353;
    cin >> t;
    for (int i=1;i<=t;i++){
        ll s,t,l,ans;
        cin >> s >> t >> l;
        ans=((s-t)%M *(2*(l%M)+1)%M)%M;
        cout << "Case #" << i << ": " << ans << '\n';
    }
}