#include <bits/stdc++.h>
using namespace std;

const int N=10005,M=2012;
int dp[N][N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;
    dp[0][0]=1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=k;j++){
            dp[i][j]=dp[i-1][j];
            dp[i][j]+=dp[i][j-1];
            if (j-i>=0) dp[i][j]-=dp[i-1][j-i];
            dp[i][j]=((dp[i][j]%M)+M)%M;
        }
    }
    cout << dp[n][k];
}