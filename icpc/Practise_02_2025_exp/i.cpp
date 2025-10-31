#include <bits/stdc++.h>
using namespace std;

using db=long double;
const db pi=acos(-1.0),k=1e-5,er=1e-6;

db u,r,d,a,b,x,y,sum;

db f (db nx){
    if (abs(nx-a)<k || abs(nx+a)<k) return 0.0;
    if (b*b < b*b*nx*nx/(a*a)){
        cout << " !" << nx << ' ' << a << '\n';
    }
    return sqrt(b*b-b*b*nx*nx/(a*a));
}

db intg (db nx){
    db re=0;
    for (db i=-a+k;i<=nx-a;i+=k){
        db dy = f(i)-f(i-k);
        re+=sqrt(k*k+dy*dy);
    }
    return re;
}

int main (){
    // ios::sync_with_stdio(0); cin.tie(0);
    int test;
    cin >> test;
    while (test--){
        cin >> u >> r >> d;
        b=2.0*r;
        a=2.0*r;
        db t=0;
        a=1.0; b=1.0;
        db tmp = intg(a*2.0);
        cout << " => " << setprecision(7) << tmp << '\n';
        while (tmp-t*2.0*u>k){
            a+=k*u;
            t+=k;
            tmp=intg(a*2);
            // cout << " => " << tmp << ' ' << a << ' ' << t*2.0*u <<  ' ' << tmp-t*2.0*u << '\n';
        }
        cout << tmp;
        // x=sqrt(a*a/2 + d/2);
        // y=sqrt(b*b-b*b*x*x/(a*a));
        // sum=sqrt(y*y+(d-x)*(d-x));
        // cout << a <<  ' ' << b << ' ' << x << ' ' << y << '\n';
        // if (b>d){
        //     cout << "!" << d/(2.0*u) << '\n';
        //     continue;
        // }
        
        // cout << setprecision(12) << sum/(2.0*u) << '\n'; 
    }
    
}