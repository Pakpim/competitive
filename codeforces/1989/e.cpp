#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=200005,K=15,M=998244353;

ll s1[K][N],s2[K][N],dp1[K][N],dp2[K][N];

int main (){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i=2;i<=n;i++){
            dp1[2][i]=(dp2[2][i-1]+dp1[2][i-1]+1)%M;
            if (i-3>0) dp2[2][i]=(s1[2][i-3]+s2[2][i-3]+i-3)%M;
            s1[2][i]=(s1[2][i-1]+dp1[2][i])%M;
            s2[2][i]=(s2[2][i-1]+dp2[2][i])%M;
    }
    for (int i=3;i<=k;i++){
        for (int j=i;j<=n;j++){
            dp1[i][j]=(dp1[i-1][j-1]+dp2[i-1][j-1])%M;
            if (j-3>0) dp2[i][j]=(s1[i-1][j-3]+s2[i-1][j-3])%M;
            s1[i][j]=(s1[i][j-1]+dp1[i][j])%M;
            s2[i][j]=(s2[i][j-1]+dp2[i][j])%M;
        }
    }
    ll ans=(dp1[k][n]+dp2[k][n]+dp1[max(2,k-1)][n-2]+dp2[max(2,k-1)][n-2])%M;
    if (k==2 && n>2) ans=(ans+1)%M;
    cout << ans ;//<< ' ' << dp1[k][n] << ' ' << dp2[k][n] << ' ' << dp1[max(2,k-1)][n-2] << ' ' << dp2[k-1][n-2]; 
}
