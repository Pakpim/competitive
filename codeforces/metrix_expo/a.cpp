#include <bits/stdc++.h>
using namespace std;

using db = double;


struct mtx{
    const int d=2;
    vector<vector<db>> v;
    mtx(){
        v.resize(d);
        for (int i=0;i<d;i++) {
            v[i].resize(d,0);
            v[i][i]=1;
        }
    }
    mtx(vector<vector<db>> v):v(v){}
    mtx operator *= (const mtx &o){
        vector<vector<db>> tmp;
        tmp.resize(d);
        for (int i=0;i<d;i++){
            tmp[i].resize(d,0);
            for (int j=0;j<d;j++){
                for (int k=0;k<d;k++) tmp[i][j]+=v[i][k]*o.v[k][j];
            }
        }
        v=tmp;
        return *this;
    }
    friend mtx operator* (const mtx &lhs,const mtx &rhs){return mtx(lhs)*=rhs;}
};

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    db p;
    cin >> n >> p;
    mtx a,b({{1-p,p},{p,1-p}});
    while (n>0){
        if (n&1){
            a*=b;
        }
        b*=b;
        n>>=1;
    }
    cout << a.v[0][0];
}