#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=105, M=1e9+7;
string s[N], t;
ll dp[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> s[i];
    cin >> t;
    dp[0]=1;
    for (int i=1;i<=t.size();i++){
        for (int j=1;j<=n;j++){
            if (i<s[j].size()) continue;
            bool ok=1;
            for (int k=s[j].size()-1;k>=0;k--){
                if (t[i-k-1]=='?') continue;
                ok&=t[i-k-1]==s[j][s[j].size()-k-1];
                // cout << " ? " << k << " : " << t[i-k-1] << ' '<< s[j][k] << '\n';
            }
            // cout << " => " << t[i-1] << ' ' << s[j] << ' ' << ok << '\n';
            if (!ok) continue;
            dp[i]+=dp[i-s[j].size()];
            dp[i]%=M;
        }
    }
    cout << dp[t.size()];
}