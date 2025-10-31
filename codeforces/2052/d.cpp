#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int a[N],b[N],in[N];
vector<int> g[N],bg[N];
bool f[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int x=0,y=0;
    for (int i=1;i<=n;i++){
        string s1,s2;
        cin >> s1 >> s2;
        if (s1=="set") a[i]=1;
        if (s2=="true") {
            b[i]=1;
            if (a[i]) x=i;
            else y=i;
        }
    }
    int m;
    cin >> m;
    while (m--){
        int u,v;
        cin >> u >> v;
        if ((u==y && v==x) || (v==x && a[u] && !b[u])){
            cout << "-1";
            exit(0);
        }
        g[u].emplace_back(v);
        bg[v].emplace_back(u);
        in[v]++;
    }
    for (int i=1;i<=n;i++){
        if (!x && ((a[i] && !b[i]) || (!a[i] && b[i]))){
            cout << "-1";
            exit(0);
        }
    }
    queue<int> tmp;
    vector<int> f2(n+5,0),f3(n+5,0);
    for (int i=1;i<=n;i++){
        if (a[i] || b[i]) tmp.emplace(i);
    }
    while (!tmp.empty()){
        int nn=tmp.front(); tmp.pop();
        if (f2[nn]) continue;
        f2[nn]=1;
        if (!a[nn] && !b[nn]){
            if (!x){
                cout << "-1";
                exit(0);
            }
            g[nn].emplace_back(x);
            in[x]++;
        }
        for (auto e:bg[nn]) tmp.emplace(e);
    }
    for (int i=1;i<=n;i++){
        if (a[i] || b[i]) tmp.emplace(i);
    }
    while (!tmp.empty()){
        int nn=tmp.front(); tmp.pop();
        if (f3[nn]) continue;
        f3[nn]=1;
        if (!a[nn] && !b[nn]){
            if (!y){
                cout << "-1";
                exit(0);
            }
            g[y].emplace_back(nn);
            in[nn]++;
        }
        for (auto e:g[nn]) tmp.emplace(e);
    }
    for (int i=1;i<=n;i++){
        if(a[i] && !b[i]){
            if (!x){
                cout << "-1";
                exit(0);
            }
            g[x].emplace_back(i);
            in[i]++;
            if (y){
                g[i].emplace_back(y);
                in[y]++;
            }
        }
        if (!a[i] && !b[i] && !f3[i] && x){
            g[i].emplace_back(x);
            in[x]++;
        }
    }
    if (y){
        g[x].emplace_back(y);
        in[y]++;
    }
    queue<int> q;
    deque<int> ans;
    for (int i=1;i<=n;i++){
        if (!in[i]) q.emplace(i);
    }
    while (!q.empty()){
        auto nn=q.front();
        q.pop();
        ans.emplace_back(nn);
        f[nn]=1;
        for (auto e:g[nn]){
            in[e]--;
            if (!in[e]) q.emplace(e);
        }
    }
    if (ans.size()<n) cout << "-1";
    else{
        for (auto e:ans) cout << e << ' ';
    }
}