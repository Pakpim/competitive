#include<bits/stdc++.h>
using namespace std;

using ll=long long; 
const int N=1005;
vector<int> g[N],rg[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    while (m--){
        int u,v;
        cin >> u >> v;
        g[u].emplace_back(v);
        rg[v].emplace_back(u);
    }
    int sum=0;
    for (int i=1;i<=n;i++){
        int cnt=0;
        vector<bool> b0(n+5,0), b1(n+5,0);
        queue<int> q;
        q.emplace(i);
        while (!q.empty()){
            auto nn=q.front(); q.pop();
            if (b0[nn]) continue;
            b0[nn]=1;
            for (auto e:g[nn]) q.emplace(e);
        }
        q.emplace(i);
        while (!q.empty()){
            auto nn=q.front(); q.pop();
            if (b1[nn]) continue;
            b1[nn]=1;
            for (auto e:rg[nn]) q.emplace(e);
        }
        for (int i=1;i<=n;i++) cnt+=(b0[i] | b1[i]);
        if (cnt==n) sum++;
        // cout << i << ' ' << cnt << '\n';
    }
    cout << sum;
}