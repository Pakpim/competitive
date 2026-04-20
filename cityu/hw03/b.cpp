#include<bits/stdc++.h>
using namespace std;

using ll=long long; 
const int N=1e5+5;
vector<int> g[2][N];
int n,m,q;

bool cal (int u,int v, int id){
    queue<int> q;
    vector<bool> vis(n+2,0);
    q.emplace(u);
    while (!q.empty()){
        int nn=q.front(); q.pop();
        if (vis[nn]) continue;
        if (nn==v) return 1;
        vis[nn]=1;
        for (auto e:g[id][nn]) q.emplace(e);
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q;
    while (m--){
        int u,v;
        cin >> u >> v;
        g[0][u].emplace_back(v);
        g[1][u].emplace_back(v);
        g[1][v].emplace_back(u);
    }
    while (q--){
        int u,v;
        cin >> u >> v;
        bool b0=cal(u,v,0), b1=cal(v,u,0), b2=cal(u,v,1);
        if (b0 && b1) cout << "Strongly Connected\n";
        else if (b0 || b1) cout << "Unilaterally Connected\n";
        else if (b2) cout << "Weakly Connected\n";
        else cout << "Not Connected\n";
    }
}