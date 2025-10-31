#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=2e5+5;
ll qs[N],a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y,z,p;
    cin >> n >> m >> x >> y >> z >> p;
    int tn=n,tm=m;
    x%=4;
    y%=2;
    z%=4;
    while (p--){
        int r,c;
        m=tm,n=tn;
        cin >> r >> c;
        for (int i=0;i<x;i++){
            int xr,xc;
            xr = c;
            xc = n-r+1;
            r=xr;
            c=xc;
            swap(n,m);
        }
        if (y){
            c=m-c+1;
        }
        for (int i=0;i<z*3;i++){
            int xr,xc;
            xr = c;
            xc = n-r+1;
            r=xr;
            c=xc;
            swap(n,m);
        }
        cout << r << ' ' << c << '\n';
    }
}