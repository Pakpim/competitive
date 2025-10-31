#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=705,M=29947;
ll dp[N][N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll a,b,c,sum;
    cin >> a >> b >> c;
    a--; b--; c--;
    for (ll i=0;i<N;i++) dp[i][0]=dp[0][i]=1;
    for (ll i=1;i<N;i++){
        for (ll j=1;j<N;j++){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%M;
        }
    }
    sum=dp[b+c][a];
    for (int i=1;i<=b;i++){
        for (int j=1;j<=c;j++){
            sum+=(dp[i-1][j-1]*dp[b+c-i-j][a])%M;
            sum%=M;
        }
    }
    cout << sum;
}