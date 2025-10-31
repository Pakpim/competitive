#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
vector<int> g[N];
queue<pair<int,int>> q;
bool vis[N];
int ans=1e9;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    while (m--){
        int a,b;
        cin >> a >> b;
        g[a].emplace_back(b);
    }
    q.emplace(1,0);
    while (!q.empty()){
        auto [nn,nd]=q.front(); q.pop();
        vis[nn]=1;
        for (auto e:g[nn]){
            if (!vis[e]) q.emplace(e,nd+1);
            else if (e==1) ans=min(ans,nd+1);
        }
    }
    if (ans==1e9) cout << -1;
    else cout << ans;
}