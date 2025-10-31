#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=200005,M=998244353;
vector<pair<int,int>> v;
ll dp[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        v.emplace_back(x,y);
    }
    dp[1]=1;
    for (int i=1;i<=k;i++){
        vector<pair<ll,ll>> tmp;
        for (auto [a,b]:v){
            int ni=(((a-i+1)%n)+n)%n;
            if (!ni) ni=n;
            int nj=(((b-i)%n)+n)%n;
            if (!nj) nj=n;
            tmp.emplace_back(nj,dp[ni]);
        }
        for (auto [nn,nv]:tmp){
            dp[nn]=(dp[nn]+nv)%M;
        }
        // for (int j=1;j<=n;j++){
        //     int ni=(j-i+n)%n;
        //     if (!ni) ni=n;
        //     cout << dp[ni] << ' ';
        // }
        // cout << '\n';
    }
    ll sum=0;
    for (int i=1;i<=n;i++) sum=(sum+dp[i])%M;
    cout << sum;
}