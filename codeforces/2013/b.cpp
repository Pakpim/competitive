#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=200005;
ll a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll n,ans=0;
        cin >> n;
        for (int i=0;i<n;i++) cin >> a[i];
        ans=a[n-1];
        for (int i=0;i<n-2;i++) ans+=a[i];
        ans-=a[n-2];
        cout << ans << '\n';
    }
}