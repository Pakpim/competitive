#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5, inf=1e18;
ll dp[N][30], ans[N], qs[N][30], a[30][30];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m,k;
    string s;
    cin >> n >> m >> k >> s;
    for (int i=0;i<m;i++) for (int j=0;j<m;j++) cin >> a[i][j];
    for (int k=0;k<m;k++){
        for (int i=0;i<m;i++){
            for (int j=0;j<m;j++){
                a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<m;j++){
            ll nc = a[s[i-1]-'a'][j];
            qs[i][j]=qs[i-1][j]+nc;
        }
    }
    for (int i=1;i<=n;i++) for (int j=0;j<m;j++) dp[i][j]=ans[i]=inf;
    for (int i=1;i<=n;i++){
        if (i>=k){
            for (int j=0;j<m;j++){
                ll nc = qs[i][j]-qs[i-k][j];
                ans[i]=min(ans[i],dp[i-k][j]+nc);
            }
        }
        for (int j=0;j<m;j++){
            ll nc = a[s[i-1]-'a'][j];
            dp[i][j]=min(dp[i-1][j]+nc, ans[i]);
        }
    }
    cout << ans[n];
}