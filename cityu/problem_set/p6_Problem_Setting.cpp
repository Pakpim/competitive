#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=5005;
ll dp[N][2], mx[N][20], lg[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin >> n >> q;
    for (int i=0;i<N;i++) dp[i][0]=-1;
    dp[0][0]=0;
    for (int i=1;i<=n;i++){
        int d,f, ni=i&1, bi=ni^1;
        cin >> d >> f;
        for (int j=0;j<N;j++){
            dp[j][ni]=dp[j][bi];
            if (j-d>=0 && dp[j-d][bi]>-1) dp[j][ni]=max(dp[j][ni], dp[j-d][bi]+f);
        }
        // for (int j=0;j<=60;j++) cout << " ? " << j << ' ' << dp[j][ni] << ' ' << dp[j][bi] << '\n';
        // cout << '\n';
    }
    for (int i=0;i<N;i++) mx[i][0]=dp[i][n&1];
    for (int j=1;j<15;j++){
        for (int l=0, r=(1<<(j-1));r<N;l++,r++){
            mx[l][j]=max(mx[l][j-1],mx[r][j-1]);
        }
    }
    for (int i=1, j=0;i<N;i++){
        if (i>=(1<<j)) j++;
        lg[i]=j-1;
    }
    while (q--){
        int l,r;
        cin >> l >> r;
        int nl=lg[r-l+1], nr=r-(1<<nl)+1;
        int ans=max(mx[l][nl], mx[nr][nl]);
        cout << ans << '\n';
    }
}