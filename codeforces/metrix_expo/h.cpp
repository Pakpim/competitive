#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=200005,M = 1e9+7;
ll n,q;
string s;

struct mll{
    ll v;
    mll(): v(0){}
    mll(ll v): v(v%M){}
    mll operator += (const mll &o){v = (o.v+v)%M; return *this;}
    mll operator *= (const mll &o){v = (o.v*v)%M; return *this;}
    mll operator = (const ll &o){v = o%M; return *this;}
    friend mll operator + (const mll &lhs,const mll &rhs) {return mll(lhs)+=rhs;}
    friend mll operator * (const mll &lhs,const mll &rhs) {return mll(lhs)*=rhs;}
    friend istream &operator >> (istream &is,mll &o){
        ll x;
        is >> x;
        o=mll(x);
        return is;
    }
    friend ostream &operator << (ostream &os,mll &o){
        return os<<o.v;
    }
};

const ll d = 2;
struct mtx{
    array<array<mll,d>,d> v;
    mtx(){
        for (ll i=0;i<d;i++) {
            for (ll j=0;j<d;j++) v[i][j]=0;
            v[i][i]=1;
        }
    }
    mtx(vector<vector<mll>> v2){
        for (int i=0;i<d;i++) for (int j=0;j<d;j++) v[i][j]=v2[i][j];
    }
    mtx operator = (const mtx &o){
        v=o.v;
        return *this;
    }
    mtx operator *= (const mtx &o){
        array<array<mll,d>,d> tmp;
        for (ll i=0;i<d;i++){
            for (ll j=0;j<d;j++){
                tmp[i][j]=0;
                for (ll k=0;k<d;k++) tmp[i][j]+=v[i][k]*o.v[k][j];
            }
        }
        v=tmp;
        return *this;
    }
    friend mtx operator* (const mtx &lhs,const mtx &rhs){return mtx(lhs)*=rhs;}
}sg[N*4],ar[N];

void build (ll l=0,ll r=n-1,ll i=0){
    if (l>r) return;
    if (l==r){
        char c=s[l];
        if (c=='?') sg[i]=mtx({{19,6},{7,20}});
        else if (c=='H') sg[i]=mtx({{1,1},{0,0}});
        else if (c=='S' || c=='D') sg[i]=mtx({{0,0},{1,1}});
        else if (c=='A' || c=='E' || c=='I' || c=='O' || c=='U') sg[i]=mtx({{0,1},{1,0}});
        else sg[i]=mtx({{1,0},{0,1}});
        return;
    }
    ll mid = (l+r)/2;
    build(l,mid,i*2+1);
    build(mid+1,r,i*2+2);
    sg[i]=sg[i*2+2]*sg[i*2+1];
    return;
}

void up (ll p,char c,ll l=0,ll r=n-1,ll i=0){
    if (l>r) return;
    if (l==r){
        if (c=='?') sg[i]=mtx({{19,6},{7,20}});
        else if (c=='H') sg[i]=mtx({{1,1},{0,0}});
        else if (c=='S' || c=='D') sg[i]=mtx({{0,0},{1,1}});
        else if (c=='A' || c=='E' || c=='I' || c=='O' || c=='U') sg[i]=mtx({{0,1},{1,0}});
        else sg[i]=mtx({{1,0},{0,1}});
        return;
    }
    ll mid = (l+r)/2;
    if (p<=mid) up(p,c,l,mid,i*2+1);
    else up(p,c,mid+1,r,i*2+2);
    sg[i]=sg[i*2+2]*sg[i*2+1];
    return;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q >> s;
    build();
    mll ans = sg[0].v[0][0];
    cout << ans << '\n';
    while (q--){
        ll p;
        char c;
        cin >> p >> c;
        up(p-1,c);
        ans = sg[0].v[0][0];
        cout << ans << '\n';
    }
}