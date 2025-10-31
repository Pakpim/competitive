#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=5005,M=2553;
ll dp[2][N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,x,ans=0;
    cin >> n >> x;
    for (int i=1;i<=x;i++) dp[1][i]=1;
    for (int i=2;i<=n;i++){
        for (int j=1;j<=n;j++) dp[i&1][j]=0;
        for (int j=i;j<=n;j++) {
            dp[i&1][j]=dp[i&1][j-1]+dp[(i-1)&1][j-1];
            if (j-x>0) dp[i&1][j]-=dp[(i-1)&1][j-x-1];
            dp[i&1][j]=(dp[i&1][j]+M)%M;
            if (j==n){
                ans+=dp[i&1][n]*dp[i&1][n]*dp[i&1][n];
                ans%=M;
            }
        }
    }
    cout << ans;
}