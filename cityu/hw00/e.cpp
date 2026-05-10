#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5;
ll dp[2][N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,s, ans=0;
    cin >> n >> s;
    for (int i=0;i<N;i++) dp[0][i]=dp[1][i]=1e13;
    dp[0][0]=dp[1][0]=0;
    for (ll i=1;i<=n;i++){
        ll w,v;
        cin >> w >> v;
        for (ll j=0;j<N;j++){
            dp[i&1][j]=dp[(i&1)^1][j];
            if (j-v>=0) dp[i&1][j]=min(dp[i&1][j], dp[(i&1)^1][j-v]+w);
            if (dp[i&1][j]<=s) ans=max(ans,j);
        }
    }
    cout << ans;
}