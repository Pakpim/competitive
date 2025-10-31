#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N=25;
vector<pair<int,int>> g[N];
int n,m,mx[N],mn[N];
bool ok;
bool f[N];

int ub (){
    int sum=0;
    for (int i=0;i<n;i++){
        if (f[i]) continue;
        sum+=mx[i];
    }
    return sum;
}

bool dfs (int nn,int tg){
    if (tg<0) return 0;
    if (tg==0) return 1;
    f[nn]=1;
    if (tg>ub()){
        f[nn]=0;
        return 0;
    }
    for (const auto &[xd,xn]:g[nn]){
        if (!f[xn] && dfs(xn,tg-xd)){
            f[nn]=0;
            return 1;
        }
    }
    f[nn]=0;
    return 0;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i=0;i<n;i++) mn[i]=1e9;
    vector<int> q(8);
    for (auto &e:q) cin >> e;
    while (m--){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].emplace_back(w,v);
        g[v].emplace_back(w,u);
        mx[u]=max(mx[u],w);
        mx[v]=max(mx[v],w);
    }
    for (int i=0;i<n;i++) sort(g[i].begin(),g[i].end(),greater<pair<int,int>>());
    for (const auto &e:q){
        ok=0;
        for (int i=0;i<n;i++) {
          if(!ok) ok=dfs(i,e); 
          else break;
        }
        cout << (ok ? "YES" :"NO") <<'\n';
    }
}