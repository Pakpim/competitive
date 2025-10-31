#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5;
ll a[N],ps[N],ss[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll n,ans=0,l=1;
        cin >> n;
        ss[n+1]=0;
        for (int i=1;i<=n;i++) {
            cin >> a[i];
        }
        for (int i=1;i<=n;i++) {
            ps[i]=ps[i-1];
            if (a[i]>=0) ps[i]+=a[i];
        }
        for (int i=n;i>0;i--){
            ss[i]=ss[i+1];
            if (a[i]<0) ss[i]+=-a[i];
        }
        ans=max(ss[1],ps[n]);
        for (int i=1;i<=n;i++){
            ans=max(ans,ps[i]+ss[i+1]);
        }
        cout << ans << '\n';
    }
}