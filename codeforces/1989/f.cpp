#include<bits/stdc++.h>
using namespace std;

using ll =long long;
const ll N=400005;

vector<tuple<ll,ll,ll>> ed;
vector<ll> g[N];
stack<ll> st;
ll sz[N],par[N],in[N],low[N],bn[N],cnt,ans=0;
bool past[N];

ll root (ll nn){
    if (!par[nn]) return nn;
    return par[nn]=root(par[nn]);
}

void uni (ll a,ll b){
    a=root(a); b=root(b);
    if (a==b) return;
    if (sz[a]>sz[b]) swap(a,b);
    sz[b]+=sz[a];
    par[a]=b;
}

void dfs (int nn){
    in[nn]=low[nn]=cnt++;
    st.emplace(nn);
    for (auto xn:g[nn]){
        if (!in[xn]){
            dfs(xn);
            low[nn]=min(low[nn],low[xn]);
        }
        if (!past[xn]) low[nn]=min(low[nn],low[xn]);
    }
    if (in[nn]==low[nn]){
        while (st.top()!=nn){
            bn[st.top()]=nn;
            past[st.top()]=1;
            st.pop();
        }
        past[nn]=1;
        st.pop();
        bn[nn]=nn;
    }
}

void rec(ll l,ll r,vector<tuple<ll,ll,ll>> ne){
    if (l==r){
        for (auto &[i,u,v]:ne){
            u=root(u);
            v=root(v);
            g[u].clear(); g[v].clear();
            in[u]=low[u]=bn[u]=past[u]=0;
            in[v]=low[v]=bn[v]=past[v]=0;
        }
        for (auto [i,u,v]:ne){
            if (u==v) continue;
            g[u].emplace_back(v);
        }
        cnt=1;
        for (auto [i,u,v]:ne){
            if (in[u]) continue;
            dfs(u);
        }
        for (auto [i,u,v]:ne){
            u=root(u); v=root(v);
            if (u==v || bn[u]!=bn[v]) continue;
            if (sz[u]>1) ans-= sz[u]*sz[u];
            if (sz[v]>1) ans-= sz[v]*sz[v];
            uni(u,v);
            ans+=sz[root(u)]*sz[root(u)];
        }
        cout << ans << '\n';
        return;
    }
    ll mid=(l+r)/2;
    for (auto &[i,u,v]:ne){
        if (i>mid) continue;
        u=root(u);
        v=root(v);
        g[u].clear(); g[v].clear();
        in[u]=low[u]=bn[u]=past[u]=0;
        in[v]=low[v]=bn[v]=past[v]=0;
    }
    for (auto [i,u,v]:ne){
        if (i>mid || u==v) continue;
        g[u].emplace_back(v);
    }
    cnt=1;
    for (auto [i,u,v]:ne){
        if (i>mid || in[u]) continue;
        dfs(u);
    }
    vector<tuple<ll,ll,ll>> le,re;
    for (auto [i,u,v]:ne){
        if (i>mid || bn[u]!=bn[v]) re.emplace_back(i,u,v);
        else le.emplace_back(i,u,v);
    }
    rec(l,mid,le);
    rec(mid+1,r,re);
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m,q;
    cin >> n >> m >> q;
    for (int i=0;i<q;i++){
        ll ni,mi;
        char c;
        cin >> ni >> mi >> c;
        ni=ni*2-1;
        mi=mi*2;
        if (c=='R') ed.emplace_back(i,mi,ni);
        else ed.emplace_back(i,ni,mi);
    }
    for(int i=1;i<=n;i++) sz[i*2-1]=1;
    for(int i=1;i<=m;i++) sz[i*2]=1;
    rec(0,q-1,ed);
}