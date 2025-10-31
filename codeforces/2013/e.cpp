#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=100005;
ll a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll n,ans=0;
        ll mn=1e9,tg;
        cin >> n;
        for (int i=0;i<n;i++) cin >> a[i];
        for (int i=0;i<n;i++){
            if (a[i]<mn){
                mn=a[i];
                tg=i;
            }
        }
        swap(a[0],a[tg]);
        int p=0;
        while (p<n-1 && a[p]!=1){
            mn=1e9,tg;
            for (int i=p+1;i<n;i++){
                a[i]=gcd(a[i],a[p]);
                if (a[i]<mn){
                    mn=a[i];
                    tg=i;
                }
            }
            swap(a[p+1],a[tg]);
            p++;
            if (a[p]==a[p-1]) break;
        }
        for (int i=p+1;i<n;i++) a[i]=gcd(a[i],a[p]);
        for (int i=0;i<n;i++) ans+=a[i];
        cout << ans << '\n';
    }
}