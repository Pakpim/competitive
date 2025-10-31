#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=8e4+5;
vector<pair<ll,ll>> g[N];
ll sz[N],sum[N],hv[N],hvw[N],ans,rt;
set<ll> s;

void cal (ll uc,ll rc,ll mxl){
    ll l=0,r=1e15,mid,mx=0;
    while (l<=r){
        mid=l+(r-l)/2;
        auto it=s.lower_bound(mid);
        if (it==s.end()){
            r=mid-1;
            continue;
        }
        ll nv=*it;
        if (rc+mxl-nv>=mid){
            l=mid+1;
            mx=max(mx,mid);
        }
        else r=mid-1;
    }
    ans=max(ans,min(mx,uc));
}

void up (int nn,int pw,int np){
    s.emplace(sum[nn]);
    s.emplace(sum[nn]+pw);
    for (auto [v,w]:g[nn]) if (v!=np) {
        up(v,w,nn);
    }
}

void dfs2 (int nn,int np,int pw){
    ll uc=sum[rt]-sum[nn];
    for (auto [v,w]:g[nn]) if (v!=np && v!=hv[nn]){
        dfs2(v,nn,w);
        ll rc=sum[nn]-sum[v]-w;
        cal(uc,rc,sum[v]+w);
        cal(rc,uc,sum[v]+w);
        s.clear();
    }
    if (hv[nn]!=-1){
        dfs2(hv[nn],nn,hvw[nn]);
        ll rc=sum[nn]-sum[hv[nn]]-hvw[nn];
        cal(uc,rc,sum[hv[nn]]+hvw[nn]);
        cal(rc,uc,sum[hv[nn]]+hvw[nn]);
    }
    for (auto [v,w]:g[nn]) if (v!=np && v!=hv[nn]){
        up(v,w,nn);
    }
    s.emplace(sum[nn]);
    s.emplace(sum[nn]+pw);
}

void dfs (int nn,int np){
    int mx=0;
    sz[nn]=1;
    sum[nn]=0;
    for (auto [v,w]:g[nn]) if(v!=np) {
        dfs(v,nn);
        sz[nn]+=sz[v];
        sum[nn]+=w+sum[v];
        if (sz[v]>mx){
            mx=sz[v];
            hv[nn]=v;
            hvw[nn]=w;
        }
    }
    return;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    for (int i=0;i<=n;i++) hv[i]=-1;
    for (int i=0;i<=n;i++){
        if (g[i].size()==1){
            rt=i;
            break;
        }
    }
    dfs(rt,-1);
    dfs2(rt,-1,0);
    cout << ans;
}