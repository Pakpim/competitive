#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=2005;
ll dp[N][N],mn[N][N],mx[N][N],a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+1+n);
    for (int sz=1;sz<=n;sz++){
        for (int i=1,j=sz;j<=n;i++,j++){
            if (i==j){
                dp[i][j]=0;
                mn[i][j]=mx[i][j]=a[i];
                continue;
            }
            dp[i][j]=min(dp[i+1][j]+mx[i+1][j]-a[i], dp[i][j-1]+a[j]-mn[i][j-1]);
            mx[i][j]=max(mx[i+1][j],mx[i][j-1]);
            mn[i][j]=min(mn[i+1][j],mn[i][j-1]);
        }
    }
    cout << dp[1][n];
}