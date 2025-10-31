#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using vv=vector<vector<ll>>;
const ll M=1e9+7;

vv mul (vv a,vv b){
    vv re={{0,0,0},{0,0,0},{0,0,0}};
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            for (int k=0;k<3;k++){
                re[i][j]=(re[i][j]+(a[i][k]*b[k][j])%M)%M;
            }
        }
    }
    return re;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,a[]={1,1,0};
    vv m={{1,2,0},{1,1,1},{0,1,1}},b={{1,0,0},{0,1,0},{0,0,1}};
    cin >> n;
    while (n){
        if (n&1){
            b=mul(m,b);
        }
        m=mul(m,m);
        n>>=1;
    }
    ll c[]={0,0,0};
    for (ll i=0;i<3;i++){
        for (ll j=0;j<3;j++){
            c[i]=(c[i]+(a[j]*b[i][j])%M)%M;
        }
    }
    cout << (c[0]+(2*c[1])%M)%M;
}