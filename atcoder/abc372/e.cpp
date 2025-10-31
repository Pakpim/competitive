#include <bits/stdc++.h>
using namespace std;

const int N=200005;
int par[N],w[N];
vector<int> s[N];

int root (int nn){
    if (!par[nn]) return nn;
    return par[nn]=root(par[nn]);
}

void uni (int u,int v){
    u=root(u); v=root(v);
    if (u==v) return;
    if (w[u]>w[v]) swap(u,v);
    vector<int> tmp;
    for (auto e:s[u]) tmp.emplace_back(e);
    for (auto e:s[v]) tmp.emplace_back(e);
    sort(tmp.begin(),tmp.end());
    s[u].clear(); s[v].clear();
    for (int i=tmp.size()-1;s[v].size()<10 && i>=0;i--) s[v].emplace_back(tmp[i]);
    w[v]+=w[u]+1;
    par[u]=v;
    return;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin >> n >> q;
    for (int i=1;i<=n;i++) s[i].emplace_back(i);
    while (q--){
        int x,y,z;
        cin >> x >> y >> z;
        if (x==1){
            uni(y,z);
        }
        else{
            y=root(y);
            z--;
            if (s[y].size()<=z) cout << "-1\n";
            else cout << s[y][z] << '\n';
        }
    }
}