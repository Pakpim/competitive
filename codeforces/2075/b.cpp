#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=5005;
ll a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll n,k,ans=0;
        cin >> n >> k;
        for (int i=0;i<n;i++) cin >> a[i];
        if (k==1){
            ll mx=0;
            for (int i=1;i<n-1;i++) mx=max(mx,a[i]);
            ans = max(max(mx,a[0])+a[n-1],max(mx,a[n-1])+a[0]);
        }
        else{
            sort(a,a+n);
            for (int i=1;i<=k+1;i++) ans+=a[n-i];
        }
        cout << ans << '\n';
    } 
}