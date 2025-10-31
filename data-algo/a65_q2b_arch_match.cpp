#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=505;
ll a[N],dp[N][N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int sz=2;sz<=n;sz++){
        for (int l=1,r=sz;r<=n;l++,r++){
            dp[l][r]=a[l]*a[r];
            dp[l][r]+=dp[l+1][r-1];
            dp[l][r]=max(dp[l][r],0ll);
            for (int k=l;k<r;k++){
                dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]);
            }
            // cout << l << ' ' << r << " => " << dp[l][r] << '\n';
        }
    }
    cout << dp[1][n];
}