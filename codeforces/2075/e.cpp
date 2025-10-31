#include <bits/stdc++.h>
using namespace std;

using ll=long long;

struct mll{
    ll v;
    ll M = 998244353;
    mll(): v(0){}
    mll(ll v): v(v%M){}
    mll operator += (const mll &o){v = (o.v+v)%M; return *this;}
    mll operator -= (const mll &o){v = (((v-o.v)%M)+M)%M; return *this;}
    mll operator *= (const mll &o){v = (o.v*v)%M; return *this;}
    mll operator = (const ll &o){v = o%M; return *this;}
    friend mll operator + (const mll &lhs,const mll &rhs) {return mll(lhs)+=rhs;}
    friend mll operator - (const mll &lhs,const mll &rhs) {return mll(lhs)-=rhs;}
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

mll bp (mll a,mll b){
    mll re=1;
    while (b.v){
        if (b.v&1) re*=a;
        a*=a;
        b.v>>=1;
    }
    return re;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        mll n,m,a,b,ans=0;
        cin >> n >> m >> a >> b;
        if (a.v>b.v) swap(a,b),swap(n,m);
        ans = (a+1) * (b+1); // a1 = a2, b1 = b2
        // ans+= (a+1) * (a) * bp(2,n-1); // a1, a2, b1 = b2 = a1
        // ans+= (b+1) * (b) * bp(2,m-1); // a1 = a2 = b1, b1, b2
        ans+= (a+1) * (a) * bp(2,n-1) * (b-1); // a1, a2, b1, b2 = b1
        ans+= (a+1) * (a) * bp(2,n-1) * (b-1) * (bp(2,m-1)); // a1, a2, b1, b2=a1^a2^b1
        // ans+= (b-a) * (b-a-1) * bp(2,m-1) * (a+1) * (bp(2,n-1) + 1); // b1 > A, b2 > A, a1, a2=b1^b2^a1 or a1
        // ans+= (b-a) * (a+1) * bp(2,m-1) * (a) * (bp(2,n-1) + 1); // b1 > A, b2 <= A, a1, a2=b1^b2^a1 or a1
        // ans+= (a+1) * (a) * bp(2,m-1) * (a-1) * (bp(2,n-1) + 1); // b1 <= A, b2 <= A, a1, a2=b1^b2^a1 or a1
        cout << ans << '\n';
    } 
}