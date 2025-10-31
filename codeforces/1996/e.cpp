#include <bits/stdc++.h>
using namespace std;

using ll =long long;
const ll N=200005,M=1e9+7;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        ll ans=0,N2=s.size();
        vector<ll> dp((s.size()+5)*2,0),qs(s.size()+5,0);
        dp[0+N2]=1;
        for (int i=0;i<s.size();i++) {
            if (s[i]=='0') qs[i]=-1;
            else qs[i]=1;
            if (i) qs[i]=(qs[i]+qs[i-1])%M;
            ans+=((s.size()-i)*dp[qs[i]+N2])%M;
            ans%=M;
            if (i){
                dp[qs[i-1]+N2]+=(i)+1;
                dp[qs[i-1]+N2]%=M;
            }
        }
        cout << ans << '\n';
    }
}