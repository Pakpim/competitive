#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=105,M=1e6+5,inf=1e9;
int dp[M],c[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> c[i];
    for (int i=1;i<=m;i++){
        dp[i]=inf;
        for (int j=0;j<n;j++){
            if (i-c[j]>=0 && dp[i-c[j]]!=inf){
                dp[i]=min(dp[i],dp[i-c[j]]+1);
            }
        }
    }
    if (dp[m]==inf) cout << -1;
    else cout << dp[m];
}