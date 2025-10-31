#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5;
ll dp[N][2];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k;
    cin >> n >> k;
    for (ll i=1;i<N;i++) dp[i][1]=2e9;
    for (ll i=0;i<n;i++){
        ll w,v;
        cin >> w >> v;
        for (ll j=0;j<N;j++){
            dp[j][i&1]=dp[j][(i-1)&1];
            if (j-v>=0 && dp[j-v][(i-1)&1]<2e9){
                dp[j][i&1]=min(dp[j][(i-1)&1],dp[j-v][(i-1)&1]+w);
            }
        }
    }
    for (ll i=N-1;i>=0;i--){
        if (dp[i][(n-1)&1]<=k){
            cout << i;
            break;
        }
    }
}