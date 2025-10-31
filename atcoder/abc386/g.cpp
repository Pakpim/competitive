#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=505,M=998244353;
ll dp[N],dp2[N],f[N],inv[N];


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
    f[0]=1;
    for (ll i=1;i<N;i++) f[i]=(f[i-1]*i)%M;
    inv[N-1]=bp(f[N-1],M-2);
    for (ll i=N-2;i>=0;i--) inv[i]=(inv[i+1]*(i+1))%M;
    ll n,k;
    cin >> n >> k;
    dp[2]=((k)*(k+1)/2)%M;
    dp2[2]=k;
    for (ll i=3;i<=n;i++){
        for (ll x=1;x<=k;x++){
            for (ll y=1;y<i;y++){
                ll nv=(((f[n-1]*inv[y])%M)*((inv[n-1-y]*bp(k-x,n-1-y))%M))%M;
                dp2[i]=(dp2[i]+((dp2[i-1]*nv)%M))%M;
                // cout << " => " << x << ' ' << y << ' ' << nv << ' ';
                nv=((((nv*x)%M) * dp2[i-1] )+(dp[i-1]*nv)%M)%M;
                // cout << nv << '\n';
                dp[i]=(dp[i]+nv)%M;
            }
        }
    }
    cout << dp[n];
}