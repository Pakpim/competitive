#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5;
ll a[N],p[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        p[a[i]]=i;
    }
    ll l=0, r=n/2, mid, ans=1e9;
    while (l<=r){
        mid=(l+r)/2;
        bool ok=1;
        ll nr=n-mid+1, bf=0;
        for (int i=1;i<=n;i++){
            if (a[i]<=mid || a[i]>=nr) continue;
            if (a[i]<bf) ok=0;
            bf=a[i];
        }
        if (!ok) l=mid+1;
        else{
            r=mid-1;
            ans=min(ans, mid);
        }
    }
    cout << ans;
}