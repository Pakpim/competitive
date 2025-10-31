#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5;
ll a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll n,m,k;
        bool ans=0;
        cin >> n >> m >> k;
        for (ll i=0;i<k;i++) cin >> a[i];
        sort(a,a+k);
        for (ll tmp=0;tmp<2;tmp++){
            bool ok=1;
            ll tm=m,sum=0;
            for (ll i=k-1;i>=0;i--){
                if (tm<=1) break;
                if(a[i]<n*2){
                    break;
                }
                tm-=2;
                sum+=(a[i]-n*2ll)/n;
            }
            
            // cout << "? " << tm << ' ';
            if (tm-sum>0) ok=0;
            ans|=ok;
            swap(m,n);
        }
        if (ans) cout << "Yes\n";
        else cout << "No\n";
    }
}