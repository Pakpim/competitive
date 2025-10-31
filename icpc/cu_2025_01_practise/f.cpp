#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=105;
ll a[N],n,h;

bool cal (ll x){
    ll sum=0;
    for (int i=1;i<=n;i++){
        sum+=min(a[i+1]-1,a[i]+x-1) - (a[i]-1);
    }
    // cout << " => " << x << ' ' << sum << '\n';
    return sum >= h;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        cin >> n >> h;
        for (int i=1;i<=n;i++) cin >> a[i];
        a[n+1]=2e18;
        ll l=1,r=1e18+5,mid,ans=1e18+5;
        while (l<=r){
            mid=l+(r-l)/2;
            if (cal(mid)){
                ans=min(ans,mid);
                r=mid-1;
            }
            else l=mid+1;
        }
        cout << ans << '\n';
    }
}