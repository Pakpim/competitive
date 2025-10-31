#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5;
ll p[N],c[N],n,sp,sc;

bool cal(ll x){
    ll sum=0;
    for (int i=n;i>0;i--){
        sum+=c[i]*x;
        sum=max(0ll,sum-p[i]);
    }
    if (sum) return 0;
    return 1;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++) cin >> c[i],sc+=c[i];
    for (int i=1;i<=n;i++) cin >> p[i],sp+=p[i];
    ll l=0,r=sp/sc,mid,ans=0;
    while (l<=r){
        mid=l+(r-l)/2;
        if (cal(mid)){
            ans=max(ans,mid);
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout << ans;
}