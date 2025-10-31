#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=200005,K=1024,M=1e9+7;
ll p[N],a[N],dp[2][2][2];

ll bp (ll a,ll b){
    ll re=1;
    while (b){
        if (b&1) re=(re*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return re;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll inv=bp(10000,M-2);
    int t;
    cin >> t;
    while (t--){
        ll n,ans=0;
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=n;i++) cin >> p[i];
        for (int i=0;i<10;i++){
            for (int j=0;j<10;j++){
                dp[0][0][0]=1;
                dp[0][1][0]=dp[1][1][0]=dp[1][0][0]=0;
                for (int k=1;k<=n;k++){
                    int ai=a[k]>>i&1, aj=a[k]>>j&1;
                    for (auto bi:{0,1}) for (auto bj:{0,1}){
                        dp[bi][bj][k&1]=((dp[bi][bj][!(k&1)]*(10000-p[k]))%M)+((dp[bi^ai][bj^aj][!(k&1)]*p[k])%M);
                        dp[bi][bj][k&1]=(dp[bi][bj][k&1]%M * inv)%M;
                    }
                }
                ans+=(dp[1][1][n&1]*1<<(i+j))%M;
                ans%=M;
            }
        }
        cout << ans << '\n';
    }
}

/*
1
1
343
6536
944876902
*/