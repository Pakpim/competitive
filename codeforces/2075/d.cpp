#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=65;
ll dp[N][N][N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i=0;i<60;i++) for (int j=0;j<60;j++) for (int k=0;k<60;k++) dp[i][j][k]=1e18;
    dp[0][0][0]=0;
    for (ll i=1;i<60;i++){
        for (int j=0;j<60;j++){
            for (int k=0;k<60;k++){
                if (dp[j][k][i-1]<1e18){
                    if (k+i<60) dp[j][k+i][i]=min(dp[j][k+i][i-1],dp[j][k][i-1]+(1ll<<i));
                    if (j+i<60) dp[j+i][k][i]=min(dp[j+i][k][i-1],dp[j][k][i-1]+(1ll<<i));
                }
            }
        }
        for (int j=0;j<60;j++){
            for (int k=0;k<60;k++){
                if (dp[j][k][i-1]<1e18){
                    dp[j][k][i]=min(dp[j][k][i-1],dp[j][k][i]);
                }
            }
        }
    }
    // for (int i=0;i<5;i++){
    //     for (int j=0;j<10;j++) cout << dp[i][j][59]/2 << '\t';
    //     cout << '\n';
    // }
    int t;
    cin >> t;
    while (t--){
        ll x,y,mn=1e18;
        cin >> x >> y;
        for (ll i=0;i<60;i++){
            ll px = x>>i;
            for (ll j=0;j<60;j++){
                ll py = y>>j;
                if (px==py){
                    mn=min(mn,dp[i][j][59]);
                    // if (px!=0) cout << i << ' ' << j << ' ' << dp[i][j][59] << '\n';
                }
            }
        }
        cout << mn << '\n';
    }
}