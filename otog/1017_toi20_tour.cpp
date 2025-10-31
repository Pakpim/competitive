#include<bits/stdc++.h>
using namespace std;
using ll =long long;

const ll N=200005,inf=2e18;
ll n,m,l,a[15];
vector <tuple<ll,ll,ll>> g[N];
vector<pair<ll,ll>> vx,vy;

void dfs (ll nn,ll nx,ll ny){
    if (nn==n){
        vx.emplace_back(nx,ny);
        return;
    }
    for (auto [xn,xs,xw]:g[nn]){
        if (xs == 1) dfs(xn,nx+xw,ny);
        else dfs(xn,nx,ny+xw);
    }
    return;
}

ll dis (ll ax,ll ay,ll bx,ll by){
    return (ax-bx)*(ax-bx)+(ay-by)*(ay-by);
}

vector<pair<ll,ll>> tmp,tmpl,tmpr;
ll cp (ll l, ll r){
    if (l==r) {
        vy[l]={vx[l].second,vx[l].first};
        return inf;
    }
    ll mid = (l+r)/2;
    ll d = cp(l,mid);
    d = min(d,cp(mid+1,r));
    ll p1=l,p2=mid+1;
    while (p1<=mid || p2<=r){
        if ((p1<=mid && p2<=r && vy[p1]<vy[p2]) || (p2>r && p1<=mid)){
            if ((vy[p1].second-vx[mid+1].first)*(vy[p1].second-vx[mid+1].first) <= d) tmpl.emplace_back(vy[p1]);
            tmp.emplace_back(vy[p1++]);
        }
        else{
            if ((vy[p2].second-vx[mid].first)*(vy[p2].second-vx[mid].first) <= d) tmpr.emplace_back(vy[p2]);
            tmp.emplace_back(vy[p2++]);
        }
    }
    ll p=0;
    for (auto [ny,nx]:tmpl){
        while (p<tmpr.size() && tmpr[p].first<ny) p++;
        for (int i=p;i<tmpr.size() && (ny-tmpr[i].first)*(ny-tmpr[i].first)<=d;i++){
            d=min(d,dis(nx,ny,tmpr[i].second,tmpr[i].first));
        }
    }
    p=0;
    for (auto [ny,nx]:tmpr){
        while (p<tmpl.size() && tmpl[p].first<ny) p++;
        for (int i=p;i<tmpl.size() && (ny-tmpl[i].first)*(ny-tmpl[i].first)<=d;i++){
            d=min(d,dis(nx,ny,tmpl[i].second,tmpl[i].first));
        }
    }
    for (int i=0;i<r-l+1;i++) vy[l+i]=tmp[i];
    tmp.clear(); tmpl.clear(); tmpr.clear();
    return d;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> l;
    for (int i=0;i<l;i++) cin >> a[i];
    while (m--){
        ll u,v,s,w;
        cin >> u >> v >> s >> w;
        g[u].emplace_back(v,s,w);
    }
    dfs(1,0,0);
    sort(vx.begin(),vx.end());
    vy.resize(vx.size());
    cout << cp(0,vx.size()-1);
}