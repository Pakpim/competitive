#include <bits/stdc++.h>
using namespace std;

const int N=1005,M=3005;
int dp[N][M],t[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> t[i];
    for (int i=1;i<=n;i++){
        for (int j=0;j<i;j++) dp[i][j]=1e9;
        for (int j=i;j<M;j++) dp[i][j]=min(dp[i][j-1],dp[i-1][j-1]);
        for (int j=i;j<M;j++) if (j!=t[i]) dp[i][j]++;
    }
    int ans=1e9;
    for (int i=n;i<M;i++) ans=min(ans,dp[n][i]);
    cout << ans;
}