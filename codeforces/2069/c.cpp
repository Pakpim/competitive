#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5,M=998244353;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll n,ans=0,cnt=0,sum=0;
        cin >> n;
        for (ll i=1;i<=n;i++){
            ll nv;
            cin >> nv;
            if (nv==1){
                cnt=(cnt+1)%M;
                sum=(sum+1)%M;
            }
            if (nv==2){
                sum=(sum*2)%M;
            }
            if (nv==3){
                ll tmp=(((sum-cnt)%M)+M)%M;
                ans=(ans+tmp)%M;
            }
        }
        cout << ans << '\n';
    }
}