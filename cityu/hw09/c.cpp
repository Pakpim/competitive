#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct fr{
    ll num=0;
    ll den=0;
    fr(ll num,ll den):num(num),den(den){}
    bool operator<(const fr &o) const{
        return num*o.den<o.num*den;
    }
};

const ll N=2005;
using ti=tuple<fr,ll,ll,ll,ll>;
ll par[N], sz[N], sum[N][N], t[N], x[N],y[N];
priority_queue<ti,vector<ti>,greater<ti>> pq;

ll root(ll nn){
    if (!par[nn]) return nn;
    return par[nn]=root(par[nn]);
}

ll dist (ll a, ll b){
    return (x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]);
}

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    ll nt=0;
    for (ll i=1;i<=n;i++){
        cin >> x[i] >> y[i];
        t[i]=nt++;
        sz[i]=1;
    }
    for (ll i=1;i<=n;i++){
        for (ll j=1;j<i;j++){
            sum[i][j]=dist(i,j);
            pq.emplace(fr(sum[i][j],1),min(t[i],t[j]), max(t[i],t[j]),i,j);
        }
    }
    while (!pq.empty()){
        auto [nd,mnt,mxt,u,v]=pq.top();
        pq.pop();
        u=root(u); v=root(v);
        if (min(t[u],t[v])!=mnt || max(t[u],t[v])!=mxt || u==v) continue;
        if (sz[u]<sz[v]) swap(u,v);
        par[v]=u;
        sz[u]+=sz[v];
        t[u]=nt++;
        cout << sz[u] << '\n';
        for (ll i=1;i<=n;i++){
            if (root(i)!=i || i==u) continue;
            sum[max(u,i)][min(u,i)]+=sum[max(v,i)][min(v,i)];
            pq.emplace(fr(sum[max(u,i)][min(u,i)],sz[u]*sz[i]), min(t[u],t[i]), max(t[u],t[i]),u,i);
        }
    }
}