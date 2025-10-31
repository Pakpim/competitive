#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=305;
int a[N],b[N][N],dp[N][N][N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int l,n,m;
        cin >> l >> n >> m;
        for (int i=1;i<=l;i++) cin >> a[i];
        for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin >> b[i][j];
        for (int i=1;i<=l+1;i++) for (int j=1;j<=n+1;j++) for (int k=1;k<=m+1;k++) dp[i][j][k]=0;
        for (int i=l;i>0;i--){
            for (int j=n;j>0;j--){
                for (int k=m;k>0;k--){
                    dp[i][j][k]=dp[i][j+1][k]|dp[i][j][k+1];
                    if (a[i]==b[j][k]) dp[i][j][k]|=~dp[i+1][j+1][k+1];
                }
            }
        }
        if (dp[1][1][1]) cout << "T\n";
        else cout << "N\n";
    }
}