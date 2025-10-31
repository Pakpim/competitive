#include <bits/stdc++.h>
using namespace std;

using ll=long long;

struct mll{
    ll v;
    ll M = 1e9+7;
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

struct mtx{
    ll d;
    vector<vector<mll>> v;
    mtx(ll d):d(d){
        v.resize(d);
        for (ll i=0;i<d;i++) {
            v[i].resize(d,0);
            v[i][i]=1;
        }
    }
    mtx(vector<vector<mll>> v):d(v.size()),v(v){}
    mtx operator *= (const mtx &o){
        vector<vector<mll>> tmp(d);
        for (ll i=0;i<d;i++){
            tmp[i].resize(d,0);
            for (ll j=0;j<d;j++){
                for (ll k=0;k<d;k++) tmp[i][j]+=v[i][k]*o.v[k][j];
            }
        }
        v=tmp;
        return *this;
    }
    friend mtx operator* (const mtx &lhs,const mtx &rhs){return mtx(lhs)*=rhs;}
};

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m,k;
    cin >> n >> m >> k;
    vector<vector<mll>> tmp(n);
    for (int i=0;i<n;i++) tmp[i].resize(n,0);
    while (m--){
        int u,v;
        cin >> u >> v;
        tmp[v-1][u-1]=1;
    }
    mtx a(n),b(tmp);
    while (k>0){
        if (k&1){
            a*=b;
        }
        b*=b;
        k>>=1;
    }
    mll ans = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) ans+=a.v[i][j];
    }
    cout << ans;
}