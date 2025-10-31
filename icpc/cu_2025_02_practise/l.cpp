#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=155;
vector<tuple<int,int,int>> edge;
vector<tuple<int,int>> up[N];
vector<int> g[N];
vector<int> tmp;
int d[N];
bitset<N>a[N],at[N],b[N],bt[N],x[N],s,ts,vis;
queue<tuple<int,int>> q;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        if (w) edge.emplace_back(w,u,v);
        else g[u].emplace_back(v);
    }
    sort(edge.begin(),edge.end());
    for (auto [w,u,v]:edge) {
        if (tmp.empty() || tmp.back()<w) tmp.emplace_back(w);
        up[tmp.size()].emplace_back(u,v);
        d[tmp.size()]=w;
    }
    s[1]=1;
    q.emplace(0,1);
    while (!q.empty()){
        auto [nd,nn]=q.front(); q.pop();
        if (nn==n){
            cout << nd;
            exit(0);
        }
        if (vis[nn]) continue;
        vis[nn]=1;
        for (auto e:g[nn]) q.emplace(nd+1,e);
    }
    for (int k=1;k<=tmp.size();k++){
        for (auto i=1;i<=n;i++) a[i].reset(),at[i].reset(),b[i].reset(),bt[i].reset();
        for (int i=1;i<=n;i++){
            for (auto e:g[i]) a[i][e]=at[e][i]=1;
        }
        // cout << " -> " << s << ' ' << d[k] << '\n';
        // for (int di=0;di<=n;di++) cout << di << " : " << a[di] << '\n';
        // cout << '\n';
        for (int i=1;i<=n;i++) b[i][i]=bt[i][i]=1;
        int nm = d[k]-d[k-1];
        while (nm){
            if (nm&1){
                // cout << " ? " << nm << ' ' << bitset<N>(nm) << '\n';
                // for (int di=0;di<=n;di++) cout << di << " : " << b[di] << '\n';
                // cout << '\n';
                for (int i=1;i<=n;i++){
                    for (int j=1;j<=n;j++){
                        x[i][j]=(b[i]&at[j]).any();
                    }
                }
                for (int i=1;i<=n;i++){
                    b[i]=x[i];
                    for (int j=1;j<=n;j++){
                        bt[j][i]=x[i][j];
                    }
                }
                // for (int di=0;di<=n;di++) cout << di << " : " << b[di] << '\n';
                // cout << '\n';
            }
            for (int i=1;i<=n;i++){
                for (int j=1;j<=n;j++){
                    x[i][j]=(a[i]&at[j]).any();
                }
            }
            for (int i=1;i<=n;i++){
                a[i]=x[i];
                for (int j=1;j<=n;j++){
                    at[j][i]=x[i][j];
                }
            }
            nm>>=1;
        }
        for (auto [u,v]:up[k]) g[u].emplace_back(v);
        for (int i=1;i<=n;i++){
            ts[i]=(s&bt[i]).any();
        }
        s=ts;
        for (int i=1;i<=n;i++) if (s[i]) q.emplace(d[k],i);
        // cout << " -> " << s << ' ' << d[k] << '\n';
        // for (int di=0;di<=n;di++) cout << di << " : " << b[di] << '\n';
        // cout << '\n';
        vis.reset();
        while (!q.empty()){
            auto [nd,nn]=q.front(); q.pop();
            if (nn==n){
                cout << nd;
                exit(0);
            }
            if (vis[nn]) continue;
            vis[nn]=1;
            for (auto e:g[nn]) q.emplace(nd+1,e);
        }
    }
    cout << "Impossible";
}