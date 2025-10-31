#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using mll=unsigned int;

struct mtx{
    ll d=11;
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
    ll n;
    mtx a,b({{0,0,0,0,0,2,0,0,0,0,0},
             {0,0,1,0,0,0,1,1,0,0,0},
             {0,1,0,0,0,1,1,0,1,0,0},
             {0,0,0,0,1,1,0,1,1,0,0},
             {0,0,0,2,0,0,0,0,2,0,0},
             {1,0,1,1,0,0,1,0,1,1,0},
             {0,1,1,0,0,1,0,1,1,1,0},
             {0,2,0,2,0,0,2,0,0,2,0},
             {0,0,1,1,1,1,1,0,2,1,0},
             {0,0,0,0,0,2,2,2,2,0,0},
             {0,0,0,0,0,2,0,0,0,0,1}});
    cin >> n;
    while (n>0){
        if (n&1){
            a*=b;
        }
        b*=b;
        n>>=1;
    }
    mll ans = 0;
    for (int i=0;i<11;i++) ans+=a.v[10][i];
    cout << ans;
}