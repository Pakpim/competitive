#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=50005;
vector<int> g[N];
ll hv[N],sz[N],cnt[N+500],ans;
int n,k;
map<ll,ll> mp;

void fl (int nn,int nd,int np){
    for (auto e:g[nn]) if (e!=np){
        fl(e,nd+1,nn);
    } 
    mp[nd]++;
}

void cl (int nn,int nd,int np){
    for (auto e:g[nn]) if (e!=np){
        cl(e,nd+1,nn);
    } 
    cnt[nd]--;
}

void dfs2(int nn,int nd,int np){
    for (auto e:g[nn]) if (e!=np && e!=hv[nn]){
        dfs2(e,nd+1,nn);
        cl(e,nd+1,nn);
    }
    if (hv[nn]) {
        dfs2(hv[nn],nd+1,nn);
    }
    for (auto e:g[nn]) if (e!=np && e!=hv[nn]){
        mp.clear();
        fl(e,nd+1,nn);
        for (auto [d,c]:mp){
            // cout << " ?? " << d << ' ' << c <<
            int i=d-nd;
            if (k-i>0) {
                ll nv = c*cnt[nd+k-i];
                ans += nv;
                // cout << "? " << i << ' ' << nv << '\n';
            }
        }
        for (auto [d,c]:mp){
            cnt[d]+=c;    
        }
    }
    cnt[nd]++;
    ans += cnt[nd+k];
    // cout << " => " << nn << ' ' << hv[nn] << '\n';
    // for (int i=0;i<=10;i++) cout << cnt[i] << ' ';
    // cout << '\n';
}

void dfs (int nn,int np){
    sz[nn]=1;
    int mx=0;
    for (auto e:g[nn]) if (e!=np) {
        dfs(e,nn);
        sz[nn]+=sz[e];
        if (sz[e]>mx){
            hv[nn]=e;
            mx=sz[e];
        }
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1,0);
    dfs2(1,0,0);
    cout << ans;
}