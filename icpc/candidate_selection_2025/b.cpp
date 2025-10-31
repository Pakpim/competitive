#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<pair<int,int>> g[N];



int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,k;
        cin >> n >> k;
        for (int i=1;i<n;i++){
            int u,v,w;
            cin >> u >> v >> w;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }

    }
}