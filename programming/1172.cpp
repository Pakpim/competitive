#include <bits/stdc++.h>
using namespace std;

const int N=1005,M=10001;
int dp[N][N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,sum;
    cin >> n;
    dp[1][1]=1;
    for (int i=2;i<=n;i++){
        sum=0;
        for (int j=i;j>0;j--){
            sum=(sum+dp[i-1][j-1])%M;
            dp[i][j]=sum;
        }
    }
    sum=0;
    for (int i=1;i<=n;i++) sum=(sum+dp[n][i])%M;
    cout << sum;
}