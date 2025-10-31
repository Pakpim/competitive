#include <bits/stdc++.h>
using namespace std;

using ll=long long;
vector<ll> p;

ll cal (ll n){
    ll l=1,r=1e9,mid,ans=0;
    while (l<=r){
        mid=(l+r)/2;
        if (mid*mid<=n){
            ans=max(ans,mid);
            l=mid+1;
        }
        else r=mid-1;
    }
    return n-ans;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll k,l=1,r=1e18+1e9,mid,ans=r;
        cin >> k;
        while (l<=r){
            mid=l+(r-l)/2ll;
            if (cal(mid)>=k){
                ans=min(ans,mid);
                r=mid-1;
            }
            else l=mid+1;
        }
        cout << ans << '\n';
    }
}