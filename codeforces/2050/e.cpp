#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using db=double;
const ll N=2e3+5;
ll dp[N][N];

void solve(){
    string a,b,c;
    cin >> a >> b >> c;
    for (int i=0;i<=a.size();i++){
        for (int j=0;j<=b.size();j++){
            if (i && j) dp[i][j]=min(dp[i-1][j]+(a[i-1]!=c[i+j-1]),dp[i][j-1]+(b[j-1]!=c[i+j-1]));
            else if (i) dp[i][j]=dp[i-1][j]+(a[i-1]!=c[i-1]);
            else if (j) dp[i][j]=dp[i][j-1]+(b[j-1]!=c[j-1]);
            // cout << i << ' ' << j << " = " << dp[i][j] << '\n';
        }
    }
    cout << dp[a.size()][b.size()] << '\n';
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}