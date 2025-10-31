#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using pi=pair<ll,ll>;
using bts=bitset<5>;
const ll N=10005,K=20;
ll dp[N][K],nc[N][35];
vector<pair<ll,ll>> v[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,c;
    cin >> n >> c;
    while (c--){
        ll id,nn[2];
        cin >> id >> nn[0] >> nn[1];
        ll h[2]={0,0};
        for (ll i=0;i<2;i++){
            for (ll j=0;j<nn[i];j++){
                ll p;
                cin >> p;
                if (p<id) p+=n;
                h[i]|=1<<(p-id);
            }
        }
        // cout << " ? " << id << ' ' << bts(h[0]) << ' ' << bts(h[1]) << '\n';
        v[id].emplace_back(h[0],h[1]);
    }
    for (ll i=1;i<=n;i++){
        for (ll j=0;j<32;j++){
            for (auto [h1,h2]:v[i]){
                if (((~j)&h1) || (j&h2)) nc[i][j]++;
            }
        }
    }
    ll ans=0;
    for (ll j=0;j<16;j++){
        for (ll i=1;i<=n;i++) for (int k=0;k<16;k++) dp[i][k]=-1e9;
        dp[0][j]=0;
        for (ll i=1;i<=n;i++){
            // cout << i << " : ";
            // for (ll j=0;j<32;j++) if (nc[j]) cout << bts(j) << ":" << nc[i][j] << '\n';
            // cout << '\n';
            for (ll k=0;k<16;k++){
                for (ll l=0;l<2;l++){
                    ll nv=dp[i-1][k];
                    ll nb=(k)|(l<<4);
                    // dp[i][nb>>1]=max(nv,dp[i][nb>>1]);
                    // if (i>n-4 && ((nb>>(n-i+1))^(j%(1<<(i-n+5))))){
                    //     continue;
                    // }
                    if (i<5 && ((j>>(i-1))^(nb%(1<<(5-i))))){
                        continue;
                    }
                    nv+=nc[i][nb];
                    // cout << "? " << nv << '\n';
                    // if (i==5 && j==0) cout << " => " << bts(j) << ' ' << bts(nb) << ' ' << nv << ' ' << nc[i][nb] << '\n';
                    dp[i][nb>>1]=max(nv,dp[i][nb>>1]);
                    // if (i==n) ans=max(dp[n][nb>>1],ans);
                }
            }
        }
        ans=max(ans,dp[n][j]);
    }
    cout << ans;
}