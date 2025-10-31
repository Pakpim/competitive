#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=3005;
vector<int> g[N];
int dis[N][N], par[N][N];
set<tuple<int,int,int>> s;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    while (m--){
        ll u,v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    while (k--){
        int a,b,c;
        cin >> a >> b >> c;
        s.emplace(a,b,c);
    }
    for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) dis[i][j]=1e9;
    queue<tuple<int,int,int,int>> q;
    q.emplace(1,0,0,0);
    dis[1][0]=0;
    int mn = 1e9;
    while (!q.empty()){
        auto [nn,bn,nd,np] = q.front();
        q.pop();
        if (dis[nn][bn]<nd) continue;
        if (nn==n) mn=min(mn,nd);
        dis[nn][bn] = nd;
        par[nn][bn] = np;
        for (auto e:g[nn]){
            if (!s.count({bn,nn,e}) && dis[e][nn]>nd+1) {
                dis[e][nn]= nd+1;
                q.emplace(e,nn,nd+1,bn);
            }
        }
    }
    for (int i=0;i<=n;i++) if (dis[n][i]!=1e9 && dis[n][i]==mn){
        cout << dis[n][i] << '\n';
        stack<int> st;
        int nn = n, bn = i;
        while (nn!=1){
            st.emplace(nn);
            int tmp = bn;
            bn= par[nn][bn];
            nn= tmp;
        }
        st.emplace(1);
        while (!st.empty()){
            cout << st.top() << ' ';
            st.pop();
        }
        return 0;
    }
    cout << -1;
}