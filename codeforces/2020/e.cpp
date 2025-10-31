#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=200005,K=1024,M=1e9+7;
ll p[N],a[N],dp[2][K];

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
        int n,ans=0;
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=n;i++) cin >> p[i];
        for (int i=0;i<1024;i++) dp[0][i]=0;
        dp[0][0]=1;
        for (int i=1;i<=n;i++){
            for (int j=0;j<1024;j++){
                dp[i&1][j]=dp[(i-1)&1][j]*(10000-p[i])+dp[(i-1)&1][(j^a[i])]*(p[i]);
                dp[i&1][j]=(dp[i&1][j]%M *inv)%M;
            }
        }
        for (int i=0;i<1024;i++){
            ans=(ans+((dp[n&1][i]*i*i)%M))%M;
        }
        cout << ans << '\n';
    }
}

/*
1
1
343
6536
2
343 624
6536 5326
3
343 624 675
6536 5326 7648
4
343 624 675 451
6536 5326 7648 2165
5
343 624 675 451 902
6536 5326 7648 2165 9430
6
343 624 675 451 902 820
6536 5326 7648 2165 9430 5428

944876902
931778969
266958585
990764439
221216198
280120536
*/