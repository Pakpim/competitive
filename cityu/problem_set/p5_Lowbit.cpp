#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5;
ll dp[N][2];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    for (int i=0;i<=s.size();i++) dp[i][0]=dp[i][1]=1e9;
    dp[s.size()][0]=0;
    for (int i=s.size()-1;i>=0;i--){
        if (s[i]=='0'){
            dp[i][0]=min(dp[i+1][0], dp[i+1][1]+1);
            if (dp[i+1][1]<1e9) dp[i][1]=dp[i+1][1]+1;
        }
        if (s[i]=='1'){
            dp[i][0]=dp[i+1][0]+1;
            dp[i][1]=min(dp[i+1][0]+1, dp[i+1][1]);
        }
        // cout << s[i] << ' ' << dp[i][0] << ' ' << dp[i][1] << '\n';
    }
    cout << min (dp[0][0], dp[0][1]+1);
}