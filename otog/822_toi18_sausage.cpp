#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=5005;
ll a[N],mx[N],dp[N][N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) dp[i][i]=a[i];
    for (int sz=2;sz<=n;sz++){
        for (int l=1,r=sz;r<=n;l++,r++){
            dp[l][r]=max(dp[l+1][r]+a[l],dp[l][r-1]+a[r]);
            dp[l][r]+=abs(a[l]-a[r]);
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            mx[i]=max(mx[i],mx[j-1]+dp[j][i]);
        }
    }
    cout << mx[n];
}