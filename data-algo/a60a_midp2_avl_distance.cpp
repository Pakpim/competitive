#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=5e4+5;
vector<int> g[N],v[N];
ll cnt,n,k;

void dfs(int nn){
    for (auto e:g[nn]){
        dfs(e);
        for (auto dis:v[e]){
            v[nn].emplace_back(dis+1);
            if (dis+1==k) cnt++;
        }
    }
    v[nn].emplace_back(0);
    sort(v[nn].begin(),v[nn].end());
    if (g[nn].size()==2){
        int lc=g[nn][0],rc=g[nn][1];
        for (auto dis:v[lc]){
            auto itl=lower_bound(v[rc].begin(),v[rc].end(),k-dis-2);
            auto itr=upper_bound(v[rc].begin(),v[rc].end(),k-dis-2);
            if (itl==v[rc].end() || *itl!=k-dis-2) {
                continue;
            }
            cnt+=itr-itl;
        }
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        g[u].emplace_back(v);
    }
    dfs(1);
    cout << cnt;
}