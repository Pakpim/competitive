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
        ll n,k,d;
        cin >> n >> k >> d;
        
    }
}