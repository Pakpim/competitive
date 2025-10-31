#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const int N=305;
const int MOD=1e9+7;

int n;
int l[N],r[N];
ll dp[N][N][N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> l[i] >> r[i];
    }
    for(int i=l[1];i<=r[1];i++){
        dp[1][1][i]=(i==1?2:1);
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int t=l[i];t<=r[i];t++){
                for(int k=0;k<=n;k++){
                    dp[i][j+1][k+t]+=dp[i-1][j][k]*(t==1?2:1);
                    if(k>=1){
                        dp[i][j][k-1+t]+=dp[i-1][j][k]*k*(t==1?2:1);
                    }
                }
                if(t==2){
                    for(int k=0;k<=n;k++){
                        dp[i][j][k+1]+=dp[i-1][j][k]*j*2;
                        dp[i][j-1][k]+=dp[i-1][j][k]*k*(j-1)*2;
                    }
                }
            }
        }
        // cerr << " === " << i << " === " << "\n";
        // cerr << "\t";
        // for(int k=0;k<=n;k++) cerr << k << " \n"[k==n];
        // for(int k=0;k<=n;k++) cerr << "---";
        // cerr << "\n";
        for(int j=0;j<=n;j++){
            // cerr << j << " |\t";
            for(int k=0;k<=n;k++){
                dp[i][j][k]%=MOD;
                // cerr << dp[i][j][k] << " \n"[k==n];
            }
        }
    }
    cout << dp[n][1][0]%MOD;
}