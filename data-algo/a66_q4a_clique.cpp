#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using bs=bitset<5>;
const int N=55,K=1<<26;
int b[N][2],qs[N][2],ans,x,y;
ll f[N][2];
int dp[K];

void dfs1(ll nb,int ni,int sum){
    ans=max(ans,sum);
    dp[nb]=sum;
    if (ni>=x) return;
    dfs1(nb,ni+1,sum);
    ll xb=nb|1ll<<ni;
    if ((f[ni][0]&xb)==xb) dfs1 (xb,ni+1,sum+b[ni][0]);
}

void dfs2(ll nb,int ni,int sum,int ns){
    if (sum+dp[ns]+qs[ni][1]<=ans) return;
    ans=max(ans,sum+dp[ns]);
    if (ni>=y) return;
    dfs2(nb,ni+1,sum,ns);
    ll xb=nb|1ll<<ni;
    if ((f[x+ni][1]&xb)==xb) dfs2 (xb,ni+1,sum+b[ni][1],ns&f[x+ni][0]);
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    x=min(n/2,20);
    y=n-x;
    for (int i=0;i<x;i++) cin >> b[i][0];
    for (int i=0;i<y;i++) cin >> b[i][1];
    for (int i=x-1;i>=0;i--) qs[i][0]=qs[i+1][0]+b[i][0];
    for (int i=y-1;i>=0;i--) qs[i][1]=qs[i+1][1]+b[i][1];
    for (int i=0;i<n;i++){
        for (int j=0;j<x;j++){
            ll ok; cin >> ok;
            f[i][0]|=ll(ok<<j);
        }
        for (int j=0;j<y;j++){
            ll ok; cin >> ok;
            f[i][1]|=ll(ok<<j);
        }
    } 
    // for (int i=0;i<1<<x;i++){
    //     dp[i]=-1;
    //     int sum=0;
    //     bool ok=1;
    //     for (int j=0;j<x;j++){
    //         if (i&1<<j) {
    //             ok&=(f[j][0]&i)==i;
    //             sum+=b[j][0];
    //         }
    //     }
    //     if (ok) dp[i]=sum;
    //     ans=max(ans,dp[i]);
    // }
    dfs1(0,0,0);
    for (int i=0;i<1<<x;i++){
        for (int j=0;j<x;j++){
            if (i&1<<j) dp[i]=max(dp[i],dp[i-(1<<j)]);
        }
    }
    dfs2(0,0,0,(1<<x)-1);
    cout << ans;
}