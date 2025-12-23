#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e6+5;
bool f[N];

void solve(){
    string a,b;
    cin >> a >> b;
    vector<int> x,y,tg;
    int tmp=0;
    for (auto e:a) x.emplace_back(e-'0');
    for (auto e:b) y.emplace_back(e-'0');
    for (auto e:x){
        tmp^=e;
        tg.emplace_back(tmp);
    }
    int n=a.size();
    vector<int> dp[2];
    dp[0].resize(n+5,0);
    dp[1].resize(n+5,0);
    for (int i=n-1;i>=0;i--){
        if (tg[i]==y[i]){
            dp[0][i]=min(dp[0][i+1], dp[1][i+1]+1);
            dp[1][i]=min(dp[0][i+1]+1, dp[1][i+1]+1);
        }
        else{
            dp[0][i]=min(dp[0][i+1]+1, dp[1][i+1]+1);
            dp[1][i]=min(dp[1][i+1], dp[0][i+1]+1);
        }

    }
    cout << min(dp[0][0], dp[1][0]+1) << '\n';
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t=0;
    cin >> t;
    while (t--){
        solve();
    }
}