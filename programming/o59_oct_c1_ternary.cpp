#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=105,M=1e9+7;

ll dp[N][N],a[N],p[N],mn[N][N],mx[N][N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
        int nn;
        cin >> nn;
        p[nn]=i;
    }
    for (int i=1;i<=n;i++) dp[i][i]=1,mn[i][i]=p[a[i]],mx[i][i]=p[a[i]];
    for (int sz=2;sz<=n;sz++){
        for (int l=1;l+sz-1<=n;l++){
            int r=l+sz-1;
            mn[l][r]=min(mn[l][r-1],p[a[r]]);
            mx[l][r]=max(mx[l][r-1],p[a[r]]);
            if (p[a[l]]>p[a[l+1]]){
                if (p[a[l]]>mx[l+1][r]) dp[l][r]=dp[l+1][r];
                for (int k1=l+1;k1<r;k1++){
                    if (mx[l+1][k1]>p[a[l]] || mn[k1+1][r]<p[a[l]] || mx[l+1][k1]>mn[k1+1][r]) continue;
                    dp[l][r]+=(dp[l+1][k1]*((dp[k1+1][r]*2)%M))%M;
                    dp[l][r]%=M;
                    for (int k2=k1+1;k2<r;k2++){
                        if (mx[k1+1][k2]>mn[k2+1][r]) continue;
                        dp[l][r]+=(dp[l+1][k1]*((dp[k1+1][k2]*dp[k2+1][r])%M))%M;
                        dp[l][r]%=M;
                    }
                }
            }
            else{
                if (p[a[l]]<mn[l+1][r]) dp[l][r]=(dp[l+1][r]*2)%M;
                for (int k1=l+1;k1<r;k1++){
                    if (p[a[l]]>mn[l+1][k1] || p[a[l]]>mn[k1+1][r] || mx[l+1][k1]>mn[k1+1][r]) continue;
                    dp[l][r]+=(dp[l+1][k1]*dp[k1+1][r])%M;
                    dp[l][r]%=M;
                }
            }
            // cout << " => " << l << ' ' << r << ' ' << dp[l][r] << '\n';
        }
    }
    cout << dp[1][n];
}