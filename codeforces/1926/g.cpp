#include <map>
#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
const ll N=200005;
vector <int> g[N];
string s;
int dp[N][2];

void dfs (int nn,int np){
    for (auto e:g[nn]){
        if (e!=np) dfs(e,nn);
    }
    if (s[nn-1]=='S'){
        dp[nn][0]=0;
        dp[nn][1]=1e9;
        for (auto e:g[nn]){
            if (e==np) continue;
             dp[nn][0]+=min(dp[e][1]+1,dp[e][0]);
        }
    }
    if (s[nn-1]=='P'){
        dp[nn][0]=1e9;
        dp[nn][1]=0;
        for (auto e:g[nn]){
            if (e==np) continue;
            dp[nn][1]+=min(dp[e][0]+1,dp[e][1]);
        }
    }
    if (s[nn-1]=='C'){
        dp[nn][0]=dp[nn][1]=0;
        for (auto e:g[nn]){
            if (e==np) continue;
            dp[nn][0]+=min(dp[e][1]+1,dp[e][0]);
            dp[nn][1]+=min(dp[e][0]+1,dp[e][1]);
        }
    }
    // cout << " => " << nn << ' ' << dp[nn][0] << ' ' << dp[nn][1] << '\n';
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i=2;i<=n;i++){
            int a;
            cin >> a;
            g[a].emplace_back(i);
            g[i].emplace_back(a);
        }
        cin >> s;
        dfs(1,0);
        cout << min(dp[1][0],dp[1][1]) << '\n';
        for (int i=1;i<=n;i++) g[i].clear();
    }
}
