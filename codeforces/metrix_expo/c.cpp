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
    const ll d = 2;
    vector<vector<mll>> v;
    mtx(){
        v.resize(d);
        for (ll i=0;i<d;i++) {
            v[i].resize(d,0);
            v[i][i]=1;
        }
    }
    mtx(vector<vector<mll>> v):v(v){}
    mtx operator *= (const mtx &o){
        vector<vector<mll>> tmp;
        tmp.resize(d);
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
    ll n;
    cin >> n;
    mtx a,b({{1,1},{1,0}});
    while (n>0){
        if (n&1){
            a*=b;
        }
        b*=b;
        n>>=1;
    }
    mll ans = a.v[1][0];
    cout << ans;
}