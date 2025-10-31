#include <bits/stdc++.h>
using namespace std;

using ll=long long;
ll M = 1e9+7;

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

struct mtx{
    ll d;
    vector<vector<mll>> v;
    mtx(ll d):d(d){
        v.resize(d, vector<mll> (d,0));
        for (ll i=0;i<d;i++) {
            v[i][i]=1;
        }
    }
    mtx(vector<vector<mll>> v):d(v.size()),v(v){}
    mtx operator *= (const mtx &o){
        vector<vector<mll>> tmp(d, vector<mll> (d,0));
        for (ll i=0;i<d;i++){
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
    ll n,k;
    cin >> n >> k;
    ll s[n];
    vector<vector<mll>> tmp(n+3, vector<mll> (n+3,0));
    for (int i=0;i<n;i++) cin >> s[i];
    for (int i=0;i<n;i++) cin >> tmp[0][i];
    cin >> tmp[0][n] >> tmp[0][n+1] >> tmp[0][n+2];
    for (int i=1;i<n;i++) tmp[i][i-1]=1;
    tmp[n][n]=1;
    tmp[n+1][n]=1;
    tmp[n+2][n]=1;
    tmp[n+1][n+1]=1;
    tmp[n+2][n+2]=1;
    tmp[n+2][n+1]=2;
    mtx a(n+3),b(tmp);
    while (k>0){
        if (k&1)a*=b;
        b*=b;
        k>>=1;
    }
    mll ans = 0;
    for (int i=0;i<n;i++){
        ans+=a.v[n-1][i]*s[n-i-1];
    }
    ans+=a.v[n-1][n]+a.v[n-1][n+1]*n+a.v[n-1][n+2]*n*n;
    cout << ans;
}