#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=5005;
ll a[N],b[N],dp[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,k;
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=k;i++) cin >> b[i];
    for (int i=1;i<=n;i++) dp[i]=-1e9;
    dp[1]=a[1];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=k && i+j<=n;j++){
            dp[i+j]=max(dp[i+j],dp[i]+a[i+j]-b[j]);
        }
    }
    cout << dp[n];
}