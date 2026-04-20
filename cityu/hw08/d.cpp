#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e6+5,M=1e9+7;
ll pi[N], cnt[N], tg[N];
vector<int> g[N];

void dfs(int nn, int ni, vector<int> &path){
    path.emplace_back(nn);
    for (;ni<path.size() && pi[path[ni]]*2<=nn+1;ni++){
        tg[nn]=path[ni];
    }
    ni--;
    for (auto e:g[nn]) dfs(e,ni,path);
    path.pop_back();
}

void solve(){
    string s;
    cin >> s;
    for (int i=0;i<s.size();i++) g[i].clear();
    for (int i=1;i<s.size();i++){
        int j=pi[i-1];
        while (j>0 && s[i]!=s[j]) j=pi[j-1];
        if (s[i]==s[j]) j++;
        pi[i]=j;
    }
    for (int i=1;i<s.size();i++) {
        cnt[i]=0;
        if (!pi[i]) {
            g[0].emplace_back(i);
            continue;
        }
        cnt[i]=cnt[pi[i]-1]+1;
        g[pi[i]-1].emplace_back(i);
    }
    vector<int> path;
    dfs(0,0,path);
    ll ans=1;
    for (int i=0;i<s.size();i++) {
        // cout << " ? " << i << " : " << tg[i] << ' ' << pi[tg[i]] << ' ' << cnt[tg[i]] << '\n';
        ans=(ans*(cnt[tg[i]]+1))%M;
    }
    cout << ans << '\n'; 
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}