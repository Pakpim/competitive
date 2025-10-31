#include <bits/stdc++.h>
using namespace std;

using db=long double;

db bp (db a,int b){
    db re=1;
    while (b){
        if (b&1) re*=a;
        a*=a;
        b>>=1;
    }
    return re;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    while (q--){
        int n;
        cin >> n;
        db a=pow(2.0,n);
        cout << setprecision(ceil(log10l(a))) << a << '\n';
    }
}