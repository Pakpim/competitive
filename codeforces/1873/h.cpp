#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5;
vector<int> g[N];
bool vis[N],f[N];
int par[N],x,y;

void dfs(int nn,int np){
    vis[nn]=1;
    for (auto e:g[nn]) if (e!=np){
        if (vis[e]){
            x=nn;
            y=e;
            return;
        }
        if (x>0 && y>0) break;
        dfs(e,nn);
    }
}

void dfs2(int nn,int np){
    par[nn]=np;
    for (auto e:g[nn]){
        if (e!=np && (e!=x || nn!=y) && (e!=y || nn!=x)){
            dfs2(e,nn);
        }
    }
}

void solve(){
    int n,a,b;
    cin >> n >> a >> b;
    for (int i=1;i<=n;i++) g[i].clear(), vis[i]=0, f[i]=0;
    x=0, y=0;
    for (int i=1;i<=n;i++){
        int u,v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1,0);
    // cout << " ? " << x << ' ' << y << '\n';
    dfs2(x,0);
    int nnn=y;
    while (nnn!=0){
        // cout << " => " << nnn << '\n';
        f[nnn]=1;
        nnn=par[nnn];
    }
    int tg=-1, d=-1;
    // for (int i=1;i<=n;i++) cout << f[i] << ' '; cout << '\n';
    queue<tuple<int,int,int>> q;
    q.emplace(b,0,0);
    while (!q.empty()){
        auto [nn,np,nd]=q.front(); q.pop();
        if (f[nn]){
            tg=nn;
            d=nd;
            break;
        }
        for (auto e:g[nn]){
            if (e!=np && !(nn==x && e==y) && !(nn==y && e==x)){
                q.emplace(e,nn,nd+1);
            }
        }
    }
    while(!q.empty()) q.pop();
    for (int i=0;i<=n;i++) vis[i]=0;
    q.emplace(a,0,0);
    while (!q.empty()){
        auto [nn,np,nd]=q.front(); q.pop();
        if (vis[nn]) continue;
        // cout << " ? " << nn << ' ' << np << ' ' << nd << '\n';
        vis[nn]=1;
        if (nn==tg){
            if (nd>d) cout << "YES\n";
            else cout << "NO\n";
            return;
        }
        for (auto e:g[nn]) q.emplace(e,nn,nd+1);
    }
    // cout << " ! " << x << ' ' << y << ' ' << tg << ' ' << d << '\n';
}

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}