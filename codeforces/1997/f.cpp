#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1005,M=998244353;
ll fi[40],f[55*N],dp[55*N][N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,x,m,ans=0;
    cin >> n >> x >> m;
    fi[1]=1; fi[2]=1;
    for (int i=3;i<=30;i++){
        fi[i]=fi[i-1]+fi[i-2];
    }
    dp[0][0]=1;
    for (int k=1;k<=x;k++){
        for (int i=1;i<=fi[x]*n;i++){
            for (int j=1;j<=n;j++){
                if (i-fi[k]>=0) dp[i][j]=(dp[i][j]+dp[i-fi[k]][j-1])%M;
            }
        }
    }
    ll p=1;
    for (int i=1;i<=fi[x]*n;i++){
        while (fi[p+1]<=i) p++;
        f[i]=f[i-fi[p]]+1;
        if (f[i]==m){
            ans=(ans+dp[i][n])%M;
        }
    }
    cout << ans;
}