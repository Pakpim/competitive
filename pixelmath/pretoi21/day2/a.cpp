#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll M=1e9+7,N=505;
ll dp[N][N][3][2];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,a[3],ans=0,v[3];
    cin >> n >> a[0] >> a[1] >> a[2];
    for (int x=0;x<3;x++){
        for (int i=0;i<=a[0];i++) for (int j=0;j<=a[1];j++) for (int k=0;k<3;k++) dp[i][j][k][0],dp[i][j][k][1]=0;
        if (x==0) dp[1][0][0][0]=1;
        if (x==1) dp[0][1][1][0]=1;
        if (x==2) dp[0][0][2][0]=1;
        for (int i=1;i<n;i++){
            int ni=i&1,nj=ni^1;
            for (int j=0;j<=a[0];j++){
                for (int k=0;k<=a[1];k++){
                    for (int y=0;y<3;y++){
                        int l=i+1-j-k;
                        dp[j][k][y][ni]=0;
                        if (l>a[2] || l<0) continue;
                        v[0]=j,v[1]=k,v[2]=l;
                        v[x]--; v[y]--;
                        if (v[0]<0 || v[1]<0 || v[2]<0) continue;
                        if (i==2){
                            if (x==y) continue;
                            if (y==0 && j) dp[j][k][y][ni]=dp[j-1][k][3-x-y][nj];
                            if (y==1 && k) dp[j][k][y][ni]=dp[j][k-1][3-x-y][nj];
                            if (y==2 && l) dp[j][k][y][ni]=dp[j][k][3-x-y][nj];
                        }
                        else{
                            if (i==1 && x==y) continue;
                            if (i==3 && y!=x) continue;
                            if (i==n-1 && y==x) continue;
                            if (y==0 && j) dp[j][k][y][ni]=dp[j-1][k][1][nj]+dp[j-1][k][2][nj];
                            if (y==1 && k) dp[j][k][y][ni]=dp[j][k-1][0][nj]+dp[j][k-1][2][nj];
                            if (y==2 && l) dp[j][k][y][ni]=dp[j][k][1][nj]+dp[j][k][0][nj];
                        }
                        dp[j][k][y][ni]%=M;
                        // cout << " => " << x << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << y;
                        // cout << " = " << dp[j][k][y][ni] << '\n';
                        if (i==n-1) ans=(ans+dp[j][k][y][ni])%M;
                    }
                }
            }
        }
    }
    cout << ans;
}