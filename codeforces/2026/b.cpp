#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2005;
ll a[N];
ll n;

ll cal (ll x){
    ll re=0;
    vector<bool> b(n,0);
    for (int i=0;i<n-1;i++){
        if (a[i+1]-a[i]>x){
            re++;
            b[i]=1;
        }
        else{
            b[i]=1;
            b[i+1]=1;
            i++;
        }
    }
    if (b[n-1]!=1) re++;
    return re;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll ans=1e18;
        cin >> n ;
        for (ll i=0;i<n;i++) cin >> a[i];
        ll l=1,r=1e18,mid;
        while (l<=r){
            mid=(l+r)/2;
            if (cal(mid)<2){
                ans=min(ans,mid);
                r=mid-1;
            }
            else l=mid+1;
        }
        cout << ans << '\n';
    }
}