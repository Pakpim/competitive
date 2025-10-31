#include <bits/stdc++.h>
using namespace std;

const int N=3e5;
int dp[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    vector<int> tmp,p;
    for (auto &[a,b]:v) cin >> a >> b;
    for(auto [a,b]:v){
        tmp.emplace_back(a);
        tmp.emplace_back(a-b);
        tmp.emplace_back(a+b);
    }
    sort(v.begin(),v.end());
    sort(tmp.begin(),tmp.end());
    for (auto e:tmp) if(p.empty() || p.back()<e) p.emplace_back(e);
    int x=1;
    for (int i=0;i<n;i++){
        auto [a,b]=v[i];
        int m = lower_bound(p.begin(),p.end(),a) - p.begin() +1;
        int l = lower_bound(p.begin(),p.end(),a-b) - p.begin() +1;
        int r = lower_bound(p.begin(),p.end(),a+b) - p.begin() +1;
        for (;x<m;x++){
            dp[x]=max(dp[x],dp[x-1]);
        }
        // cout << m << ' ' << l << ' ' << r << ": ";
        // for (int j=0;j<=p.size();j++) cout << dp[j] << ' ';
        // cout << " => ";
        if (i==0   || a-b>v[i-1].first) dp[m]=max(dp[m],dp[l-1]+1);
        if (i==n-1 || a+b<v[i+1].first) dp[r]=max(dp[r],dp[m-1]+1);
        // for (int j=0;j<=p.size();j++) cout << dp[j] << ' ';
        // cout << '\n';
    }
    for (;x<=p.size();x++){
        dp[x]=max(dp[x],dp[x-1]);
    }
    cout << dp[p.size()];
}