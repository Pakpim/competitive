#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5;
ll a[N],qs[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll n,k,cnt=0;
        cin >> n >> k;
        for (int i=1;i<=n;i++) cin >> a[i];
        sort(a+1,a+n+1);
        a[0]=0;
        a[n+1]=1e18;
        for (int i=1;i<=n;i++) qs[i]=qs[i-1]+a[i];
        ll l=0,r=1e13,mid,ans=0;
        while (l<=r){
            mid=l+(r-l)/2;
            ll idx=upper_bound(a+1,a+n+1,mid)-a;
            idx--;
            if (mid*idx-qs[idx] <= k ){
                ans=max(ans,mid);
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        if (ans==0){
            cout << "0\n";
            continue;
        }
        cnt=ans*n-n+1;
        ll idx=upper_bound(a+1,a+n+1,ans)-a;
        idx--;
        cnt+=k-(ans*idx-qs[idx]);
        for (int i=idx;i<=n;i++){
            if (a[i]-ans>=1) cnt++;
        }
        cout << cnt << '\n';
    }
}