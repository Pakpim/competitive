#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=10005,M=909091;
ll dp[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    dp[0]=1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<i;j++){
            dp[i]+=(dp[j]*dp[i-j-1])%M;
            dp[i]%=M;
        }
    }
    cout << dp[n];
}