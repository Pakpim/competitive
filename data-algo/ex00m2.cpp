#include <bits/stdc++.h>
using namespace std;

const int N=1000005;
int a[N]; 

map<int,int> b[N];
vector<int> v[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    for (int i=1;i<=n;i++) cin >> a[i];
    while (q--){
        char c;
        cin >> c;
        if (c=='B'){
            int u,i,v;
            cin >> u >> i >> v;
            b[i][u]=v;
        }
        else{
            int u,i;
            cin >> u >> i;
            if (b[i].find(u)!=b[i].end()) b[i].erase(u);
        }
    }
    for (int i=1;i<=n;i++){
        vector<pair<int,int>> od;
        for (auto [nu,nv]:b[i]) od.emplace_back(nv,nu);
        sort(od.begin(),od.end(),greater<pair<int,int>>());
        for (int j=0;j<min(int(od.size()),a[i]);j++) v[od[j].second].emplace_back(i);
    }
    for (int i=1;i<=m;i++){
        if (v[i].empty()) cout << "NONE";
        for (auto e:v[i]) cout << e << ' ';
        cout << '\n';
    }
}