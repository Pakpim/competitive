#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1005;
ll dp[N][N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,x;
    cin >> n >> x;
    for (int i=1;i<=n;i++){
        ll a;
        cin >> a;
        for (int j=1;j<=x;j++) dp[i][j]=dp[i-1][j];
        for (int j=a;j<=x;j++) {
            ll nv=a;
            if (i-2>=0) nv+=dp[i-2][j-a];
            dp[i][j]=max(dp[i][j],nv);
        }
        // for (int j=1;j<=x;j++) cout << dp[i][j] << ' ';
        // cout << '\n';
    }
    cout << dp[n][x];
}