#include <bits/stdc++.h>
using namespace std;

const int N=1005,M=1e9+7;
int dp[3][4][N],a[3];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n >> a[0] >> a[1] >> a[2];
    dp[0][0][1]=1;
    for (int i=2;i<=n;i++){
        for (int j=0;j<3;j++){
            for (int k=0;k<4;k++){
                for (int h=1;h<=min(a[j],i);h++){
                    if (j==0) dp[2][k|2][i]=(dp[2][k|2][i]+dp[0][k][i-h])%M;
                    dp[(j+1)%3][k|(j+1)%3][i]=(dp[(j+1)%3][k|(j+1)%3][i]+dp[j][k][i-h])%M;
                }
            }
        }
    }
    int sum=0;
    for (int i=0;i<3;i++){
        for (int j=0;j<a[i];j++) sum=(sum+dp[i][3][n-j])%M;
    }
    cout << sum;
}