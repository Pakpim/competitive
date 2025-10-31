#pragma GCC optimize("O3,unroll-loops")
#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <bits/stdc++.h>
using namespace std;

using db = double;
using ll = long long;
const ll N = 3000;
const db inf = -1e15;
db x[N], y[N][2], px[N*N*4],ans,w;
ll sz[N],par[N],cnt,mx,n;
vector<tuple<db,db,ll,ll>> event;
stack<tuple<ll,ll,ll>> mg;
map<db,int> pos;

struct node{
    node *lc,*rc;
    vector<pair<ll,ll>> up;
    node():lc(NULL), rc(NULL), up({}) {}
    node(node *lc,node *rc):lc(lc), rc(rc), up({}) {}
};

ll root (ll nn){
    if (!par[nn]) return nn;
    return root(par[nn]);
}

void merge (ll u,ll v,ll i){
    u=root(u); v=root(v);
    if (u==v) return;
    if (sz[u]>sz[v]) swap(u,v);
    par[u]=v;
    sz[v]+=sz[u]+1;
    mg.emplace(u,v,i);
    cnt--;
    return;
}

void undo(ll i){
    while (!mg.empty()){
        auto [u,v,ni]=mg.top();
        if (ni!=i) break;
        mg.pop();
        par[u]=0;
        sz[v]-=sz[u]+1;
        cnt++;
    }
    return;
}

void cal (ll l,ll r,ll i,node *nn){
    if (l>r) return;
    for (auto [u,v]:nn->up) merge(u,v,i);
    if (l==r) {
        if (cnt==1) {
            if (px[l]==inf){
                cout << -1;
                exit(0);
            }
            ans+=px[l+1]-px[l];
        }
    }
    else{
        ll mid=(l+r)/2;
        cal(l,mid,i*2+1,nn->lc);
        cal(mid+1,r,i*2+2,nn->rc);
    }
    undo(i);
    free(nn);
    return;
}

void push (ll l,ll r,node *nn,ll tl,ll tr,ll u,ll v){
    if (l>r) return;
    if (tl>r || tr<l) return;
    if (l>=tl && r<=tr){
        nn->up.emplace_back(u,v);
        return;
    }
    ll mid = (l+r)/2;
    if (tl<=mid) push(l,mid,nn->lc,tl,tr,u,v);
    if (tr>mid) push(mid+1,r,nn->rc,tl,tr,u,v);
    return;
}

node* build(ll l,ll r){
    if (l>r) return NULL;
    if (l==r) return new node();
    ll mid =(l+r)/2;
    return new node(build(l,mid),build(mid+1,r));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> w;
    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i][0] >> y[i][1];
    }
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (x[i] == x[j]) {
                if ((y[i][0]<y[j][0] && y[i][0]>y[j][1]) || (y[i][1]<y[j][0] && y[i][1]>y[j][1])){
                    event.emplace_back(inf,0,i,j);
                    pos.emplace(inf,0);
                    pos.emplace(0,0);
                }
                continue;
            }
            for (int k=0;k<2;k++){
                db ml=(y[i][k]-y[j][0])/(x[i]-x[j]),mr=(y[i][k]-y[j][1])/(x[i]-x[j]);
                if (y[i][k]>0) ml=max(ml,0.0),mr=max(mr,0.0);
                else ml=min(ml,0.0),mr=min(mr,0.0);
                if (abs(ml)>abs(mr)) swap(ml,mr);
                if (mr==0.0){ // the interval is empty
                    continue;
                }
                db xl, xr=(mr*x[i]-y[i][k])/mr;
                if (ml==0.0){ // the interval is infinitely far away
                    xl=inf;
                }
                else xl=(ml*x[i]-y[i][k])/ml;
                xl=min(xl,0.0); xr=min(xr,0.0);
                event.emplace_back(xl,xr,i,j);
                pos.emplace(xl,0);
                pos.emplace(xr,0);
                cout << " ? " << xl << ' ' << xr << ' ' << i << ' ' << j << '\n';
            }
        }
    }
    cnt=n;
    mx=pos.size()-1;
    px[mx+1]=0;
    ll tmp=0;
    node *rt=build(0,mx);
    for (auto &[key,val]:pos){
        val=tmp;
        px[tmp]=key;
        tmp++;
    }
    for (auto [nl,nr,u,v]:event){
        push (0,mx,rt,pos[nl],pos[nr]-1,u,v);
    }
    cal(0,mx,0,rt);
    cout << fixed << setprecision(15) << ans;
}