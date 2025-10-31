#include <bits/stdc++.h>
using namespace std;

using bs=bitset<5>;
const int N=1e6+5;
pair<int,string> dp[N];
vector<int> p;
bool f[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i=2;i<N;i++){
        if (f[i]) continue;
        p.emplace_back(i);
        for (int j=i*2;j<N;j+=i) f[j]=1;
    }
    int t=1;
    // cin >> t;
    while (t--){
        int n;
        cin >> n;
        int tmp=n;
        vector<int> fc;
        while (tmp>1){
            for (auto e:p){
                while (tmp%e==0){
                    tmp/=e;
                    fc.emplace_back(e);
                }
            }
        }
        int sz=fc.size();
        for (int i=0;i<1<<sz;i++){
            dp[i]={1,"ACV"};
            for (int j=0;j<sz;j++){
                if (i&1<<j) dp[i].first*=fc[j];
            }
            // cout << bs(i) << " = " << dp[i].first << '\n';
            for (int j=2;j<=dp[i].first;j++) dp[i].second+="V";
            dp[i].first+=2;
            for (int j=i;j>0;j=(j-1&i)){
                // cout << bs(i) << ' ' << bs(j) << ' ' << bs(i-j) << " : " << dp[j].first << ' ' << dp[i-j].first << '\n';
                dp[i]=min(dp[i],{dp[j].first+dp[i-j].first,dp[j].second+dp[i-j].second});
            }
        }
        cout << dp[(1<<sz)-1].second;
        // printf("if (i==%d) cout << \"%s\" << \'\\n\'; \n",n,dp[(1<<sz)-1].second.c_str());
    }
}

/*
10
9 30 1219 50220 124609 508394 649424 882660 945595 1000000
*/