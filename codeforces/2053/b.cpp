#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5;
ll l[N],r[N];
ll f[N*2],qs[N*2];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll n;
        string ans="";
        cin >> n;
        for (ll i=0;i<n;i++){
            cin >> l[i] >> r[i];
            if (l[i]==r[i]) f[l[i]]++;
            ans+="0";
        }
        for (int i=1;i<=n*2;i++) qs[i]=qs[i-1]+bool(f[i]);
        for (int i=0;i<n;i++){
            if (l[i]==r[i]){
                if (f[l[i]]==1) ans[i]='1';
            }
            else{
                if (qs[r[i]]-qs[l[i]-1] < r[i]-l[i]+1) ans[i]='1';
            }
        }
        cout << ans << '\n';
        for (ll i=0;i<=n*2;i++) f[i]=0;
    }
}