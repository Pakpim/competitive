#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=1005;
int ar[]={'n','a','r','e','k'}, dp[N][5];
bool ok[5];
string s[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,m;
        cin >> n >> m;
        for (int i=1;i<=n;i++) cin >> s[i];
        for (int i=0;i<=n;i++) for (int j=0;j<5;j++) dp[i][j]=-1e9;
        for (int i=0;i<5;i++) ok[i]=0;
        ok[0]=1;
        dp[0][0]=0;
        for (int i=1;i<=n;i++){
            for (int j=0;j<5;j++){
                if (!ok[j]) continue;
                int tmp=j,cnt=0,cnt2=0;
                for (auto e:s[i]){
                    if (e=='n' || e=='a' || e=='r' || e=='e' || e=='k') cnt2++;
                    if (e==ar[tmp]){
                        tmp++;
                    }
                    if (tmp==5){
                        cnt+=5;
                        tmp=0;
                    }
                }
                cnt=cnt*2-cnt2;
                // cout << i << ' ' << j << " => " << cnt << ' ' << tmp << ' ' << dp[i-1][j] << ' ';
                ok[tmp]=1;
                dp[i][tmp]=max({dp[i][tmp],dp[i-1][tmp],dp[i-1][j]+cnt});
                // cout << dp[i][tmp] << '\n';
            }
            for (int j=0;j<5;j++) dp[i][j]=max(dp[i][j],dp[i-1][j]);
            // cout << " => ";
            // for (int j=0;j<5;j++) cout << dp[i][j] << ' ';
            // cout << '\n';
        }
        int ans=0;
        for (int i=0;i<5;i++) ans=max(ans,dp[n][i]);
        cout << ans << '\n';
    }
}