#include <bits/stdc++.h>
using namespace std;

const int N=105;
vector<pair<int,int>> rg[N];
int dis[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,s;
    cin >> n >> m >> s;
    while (m--){
        int u,v,w;
        cin >> u >> v >> w;
        rg[v].emplace_back(u,w);
    }
    for (int i=0;i<n;i++) dis[i]=1e9;
    dis[s]=0;
    for (int i=1;i<n;i++){
        for (int j=0;j<n;j++){
            for (auto [e,w]:rg[j]){
                dis[j]=min(dis[j],dis[e]+w);
            }
        }
    }
    bool ok=1;
    for (int i=0;i<n;i++){
        for (auto [e,w]:rg[i]){
            if (dis[i]>dis[e]+w) ok=0;
        }
    }
    if (ok){
        for (int i=0;i<n;i++) cout << dis[i] << ' ';
    }
    else cout << "-1";
}