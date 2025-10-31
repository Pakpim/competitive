#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=2005;
int p[N],dp[N],dp2[N],in[N],out[N];
vector<int> g[N],rg[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> p[i],dp[i]=1;
    while (m--){
        int a,b;
        cin >> a >> b;
        g[a].emplace_back(b);
        rg[b].emplace_back(a);
        in[b]++;
        out[a]++;
    }
    queue<int> q;
    for (int i=1;i<=n;i++) if (!in[i]) q.emplace(i);
    while (!q.empty()){
        auto nn=q.front();
        q.pop();
        for (auto e:g[nn]){
            in[e]--;
            dp[e]+=dp[nn];
            if (!in[e]) q.emplace(e);
        }
    }
    for (int i=1;i<=n;i++){
        
    }
}