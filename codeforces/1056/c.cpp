#include <bits/stdc++.h>
using namespace std;

const int N=2e3+5;
int a[N], b[N];
set<pair<int,int>> s,p;
bool f[N];

void del(int i){
    f[i]=1;
    if (!b[i]) s.erase({a[i],i});
    p.erase({i,b[i]});
    p.erase({b[i],i});
}

void ans(int i){
    cout << i << '\n';
    cout.flush();
    del(i);
}

int main (){
    // ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n*2;i++) cin >> a[i];
    while (m--){
        int u,v;
        cin >> u >> v;
        b[u]=v;
        b[v]=u;
        if (a[u]>a[v]) swap(u,v);
        p.emplace(u,v);
    }
    for (int i=1;i<=n*2;i++){
        if (!b[i]) s.emplace(a[i],i);
    }
    int t;
    cin >> t;
    if (t==1){
        while (!p.empty()) {
            int mx=p.begin()->second;
            ans(mx);
            int x;
            cin >> x;
            if (x==-1) exit(0);
        }
        while (!s.empty()){
            ans(s.rbegin()->second);
            int x;
            cin >> x;
            if (x==-1) exit(0);
            del(x);
        }
        exit(0);
    }
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        if (x==-1) exit(0);
        del(x);
        if (b[x] && !f[b[x]]) ans(b[x]);
        else{
            if (!p.empty()){
                auto [mn,mx]=*p.begin();
                ans(mx);
            }
            else ans(s.rbegin()->second);
        }
    }
}