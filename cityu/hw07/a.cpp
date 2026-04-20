#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e6+5;
ll dp[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll a,b,s;
    cin >> a >> b >> s;
    for (int i=1;i<=s;i++){
        dp[i]=dp[i-1]+1;
        if (i-a>=0) dp[i]=min(dp[i],dp[i-a]+1);
        if (i-b>=0) dp[i]=min(dp[i],dp[i-b]+1);
    }
    cout << dp[s];
}