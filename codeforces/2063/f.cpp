#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using pi=pair<ll,ll>;
using ti=tuple<ll,ll,ll>;
const ll N=6e5+5,M=998244353;

ll bp (ll a, ll b){
    ll re=1;
    while (b){
        if (b&1) re=(re*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return re;
}

struct mll{
    ll val;
    mll():val(0){}
    mll(ll v):val(v%M){}
    mll operator+= (const mll &o){(val+=o.val)%M; return *this;}
    mll operator-= (const mll &o){val=(((val-o.val)%M)+M)%M; return *this;}
    mll operator*= (const mll &o){val=(val*o.val)%M; return *this;}
    mll operator/= (const mll &o){val=(val*bp(o.val,M-2))%M; return *this;}
    mll operator = (const mll &o){val = o.val; return *this;}
    mll operator = (const ll &o){val = o%M; return *this;}
    friend mll operator + (const mll &l,const mll &r) {return mll(l)+=r;}
    friend mll operator - (const mll &l,const mll &r) {return mll(l)-=r;}
    friend mll operator * (const mll &l,const mll &r) {return mll(l)*=r;}
    friend mll operator / (const mll &l,const mll &r) {return mll(l)/=r;}
    friend istream &operator >> (istream &is,mll &o){
        ll x;
        is >> x;
        o=mll(x);
        return is;
    }
    friend ostream &operator << (ostream &os,mll &o){
        return os<<o.val;
    }
} cat[N],inv[N],ans;
ll par[N],g[N],h[N],cnt[N],ar[N];

ll root (ll nn){
    if (par[nn]==nn) return nn;
    return par[nn]=root(par[nn]);
}

void uni(ll u,ll v){
    // cout << u << ' ' << v << " : ";
    u=root(u); v=root(v);
    if (u==v) return;
    if (g[u]==v) g[u]=g[v];
    if (g[v]==u) g[v]=g[u];
    ans*=inv[cnt[u]];
    ans*=inv[cnt[v]];
    if (h[u]>h[v]) swap(u,v);
    h[v]=max(h[v],h[u]+1);
    par[u]=v;
    cnt[v]+=cnt[u]+1;
    ans*=cat[cnt[v]];
    // cout << u << ' ' << v << " => " << cnt[u] << ' ' << cnt[v] << '\n';
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cat[0]=1;
    inv[0]=1;
    for (ll i=1;i<N;i++){
        cat[i]=(2*i)*(2*i-1)*cat[i-1];
        cat[i]/=(i*(i+1));
        inv[i]=bp(cat[i].val,M-2);
    }
    ll t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        vector<pi> ev;
        for (int i=0;i<=n*2;i++) par[i]=i,h[i]=1,cnt[i]=0;
        for (int i=0;i<n;i++){
            int a,b;
            cin >> a >> b;
            par[b]=a;
            ar[a]=1;
            ar[b]=0;
            ev.emplace_back(a,b);
        }
        deque<ll> tmp;
        tmp.emplace_back(0);
        for (int i=1;i<=n*2;i++){
            if (ar[i]){
                g[i]=tmp.back();
                tmp.emplace_back(i);
            }
            else{
                tmp.pop_back();
            }
        }
        ans=1;
        deque<mll> dq;
        dq.emplace_front(ans);
        for (int i=n-1;i>=0;i--){
            auto [a,b]=ev[i];
            uni(a,g[a]);
            dq.emplace_front(ans);
        }
        for (auto e:dq) cout << e << ' '; 
        cout << '\n';
    }
}