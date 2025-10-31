#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=1e5+5;
int c[N],ans[N],sz[N],hv[N],fw[N],n,q;
vector<int> g[N];
vector<pair<int,int>> qu[N];
map<int,int> mp;

void dfs (int nn,int np){
    sz[nn]=1;
    int mx =0;
    for (auto e:g[nn]) if (e!=np){
        dfs(e,nn);
        sz[nn]+=sz[e];
        if(sz[e]>mx){
            hv[nn]=e;
            mx=sz[e];
        }
    }
}

void up (int p,int v){
    while (p<N){
        fw[p]+=v;
        p+=p&-p;
    }
}

int fwq(int p){
    int re=0;
    while (p){
        re+=fw[p];
        p-=p&-p;
    }
    return re;
}

void rm(int nn,int np){
    for (auto e:g[nn]) if (e!=np){
        rm(e,nn);
    }
    if (mp[c[nn]]>0) up(mp[c[nn]],-1);
    mp[c[nn]]--;
    if (mp[c[nn]]>0) up(mp[c[nn]],1);
}

void add(int nn,int np){
    for (auto e:g[nn]) if (e!=np){
        add(e,nn);
    }
    if (mp[c[nn]]>0) up(mp[c[nn]],-1);
    mp[c[nn]]++;
    if (mp[c[nn]]>0) up(mp[c[nn]],1);
}

void dfs2 (int nn,int np){
    for (auto e:g[nn]) if (e!=np && e!=hv[nn]){
        dfs2(e,nn);
        rm(e,nn);
    }
    if (hv[nn]) dfs2(hv[nn],nn);
    if (mp[c[nn]]>0) up(mp[c[nn]],-1);
    mp[c[nn]]++;
    if (mp[c[nn]]>0) up(mp[c[nn]],1);
    for (auto e:g[nn]) if (e!=np && e!=hv[nn]){
        add(e,nn);
    }
    // for (auto [k,v]:mp) cout << "=>" << k << ' ' << v << '\n';
    // for (int i=1;i<=n;i++) cout << fwq(i) << ' ';
    // cout << '\n';
    for (auto [k,i]:qu[nn]){
        ans[i]=fwq(N)-fwq(k-1);
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i=1;i<=n;i++) cin >> c[i];
    for (int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for (int i=0;i<q;i++){
        int u,k;
        cin >> u >> k;
        qu[u].emplace_back(k,i);
    }
    dfs(1,0);
    dfs2(1,0);
    for (int i=0;i<q;i++) cout << ans[i] << '\n';
}