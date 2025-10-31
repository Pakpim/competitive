#include <bits/stdc++.h>
#define mid (l+r)/2
using namespace std;

using ll=long long;
const ll N=1e5+5;

struct node{
    ll pos;
    ll val;
    ll sz;
    node *lc, *rc,*p;
    node(): lc(NULL), rc(NULL), p(NULL),pos(0),val(0),sz(1) {}
    node(node *lc, node *rc): lc(lc), rc(rc), p(NULL), pos(0),val(0), sz(0){}
    node(node *lc, node *rc,node *p,ll pos,ll val): lc(lc), rc(rc), p(p), pos(pos),val(val), sz(1){}
};

ll ar[N],sg[N*4],f[N*4];
vector<ll> v[N*4];

ll qul (node *nn,ll nv){
    ll re=0;
    while (nn){
        if (nn->val < nv){
            re++;
            if (nn->lc) re+=nn->lc->sz;
            nn=nn->rc;
        }
        else{
            nn=nn->lc;
        }
    }
    return re;
}

ll qur (node *nn,ll nv){
    ll re=0;
    while (nn){
        if (nn->val > nv){
            re++;
            if (nn->rc) re+=nn->rc->sz;
            nn=nn->lc;
        }
        else{
            nn=nn->rc;
        }
    }
    return re;
}

node* del (node *nn,ll k){
    if (!nn) return NULL;
    if (!nn->lc){
        delete nn;
        return nn->rc;
    }
    if (!nn->rc){
        delete nn;
        return nn->lc;
    }
    if (k^(nn->lc->pos < nn->rc->pos)){
        node *tmp = new node(nn->lc->lc,nn->rc);
        nn->lc->rc = del(tmp,k);
        delete nn;
        return nn->lc;
    }
    else{
        node *tmp = new node(nn->lc,nn->rc->rc);
        nn->rc->lc = del(tmp,k);
        delete nn;
        return nn->rc;
    }
}

void push (node *nt,node *nl){
    
}

void build (int l,int r,int i,int k){
    if (l>r) return;
    if (k) f[i]==r;
    else f[i]==l;
    v[i].clear();
    sg[i]=0;
    if (l==r){
        v[i].emplace_back(ar[l]);
        return;
    }
    int lc=i*2+1;
    int rc=i*2+2;
    build(l,mid,lc,0);
    build(mid+1,r,rc,1);
    sg[i]=sg[lc]+sg[rc];
    int pl=0,pr=0;
    while (pl<v[lc].size()-1 || pr<v[rc].size()-1){
        if (pl<v[lc].size()-1 && pr<v[rc].size()-1){
            if (v[lc][pl]>=v[rc][pr]){
                v[i].emplace_back(v[rc][pr]);
                pr++;
            }
            else{
                sg[i]+=v[rc].size()-pr;
                v[i].emplace_back(v[lc][pl]);
                pl++;
            }
        }
        else if (pl<v[lc].size()-1){
            v[i].emplace_back(v[lc][pl]);
            pl++;
        }
        else{
            v[i].emplace_back(v[rc][pr]);
            pr++;
        }
    }
}

void up (int p,int l,int r,int i,int k){
    if (l>r) return;
    if (l==r){
        if (k) f[i]=l-1;
        else f[i]=r+1;
        return;
    }

}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i=1;i<=n;i++) cin >> ar[i];
        build(1,n,0,0);
        for (int i=0;i<n;i++){
            int p;
            cin >> p;
            int nv=sg[0];
            cout << nv;
            if (i!=n-1) cout << ' ';
            p^=nv;
            up(p,1,n,0,0);
        }
    }
}