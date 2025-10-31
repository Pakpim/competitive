#include <bits/stdc++.h>
using namespace std;

const int N=105;
int a[N],g[N][N],n,m;
bool f,vis[N];
vector <pair<int,int>> qu;
vector <tuple<int,int,int>> ans;

void dfs (int nn,int np){
    vis[nn]=1;
    if (a[nn]){
        a[nn]--;
        f=1;
    }
    for (int xn=1;xn<=n;xn++){
        if (f) break;
        if (!g[nn][xn] || xn==np || vis[xn]) continue;
        dfs(xn,nn);
    }
    if (f && np){
        g[np][nn]--;
        g[nn][np]++;
    }
    return;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    while (m--){
        int u,v;
        cin >> u >> v;
        qu.emplace_back(u,v);
        g[u][v]+=2;
        f=0;
        for (int i=1;i<=n;i++) vis[i]=0;
        dfs(u,0);
        f=0;
        for (int i=1;i<=n;i++) vis[i]=0;
        dfs(u,0);
    }
    for (auto [u,v]:qu){
        int w=min(2,g[u][v]);
        ans.emplace_back(u,v,w);
        g[u][v]-=w;
        g[v][u]-=2-w;
    }
    int tmp=0;
    for (int i=1;i<=n;i++){
        if (a[i]&1){
            if (tmp) {
                ans.emplace_back(i,tmp,1);
                tmp=0;
            }
            else tmp=i;
            a[i]--;
        }
        while (a[i]>=2){
            ans.emplace_back(i,(i%n)+1,2);
            a[i]-=2;
        }
    }
    cout << ans.size();
    for (auto [u,v,w]:ans) cout<< '\n' << u << ' ' << v << ' ' << w ;
}