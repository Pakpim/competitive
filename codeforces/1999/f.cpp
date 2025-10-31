#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=200005,M=1e9+7;

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
    mll bipow(ll d){
        mll re=1,a=v;
        while (d){
            if (d&1) re*=a;
            a*=a;
            d>>=1;
        }
        return re;
    }
}f[N],inv[N];
ll cnt[2];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    f[0]=1;
    for (int i=1;i<N;i++) f[i]=f[i-1]*mll(i);
    inv[N-1]=f[N-1].bipow(M-2);
    for (int i=N-2;i>0;i--) inv[i]=inv[i+1]*mll(i+1);
    inv[0]=1;
    ll t;
    cin >> t;
    while (t--){
        ll n,k;
        mll sum=0;
        cin >> n >> k;
        cnt[0]=0; cnt[1]=0;
        for (ll i=0;i<n;i++){
            ll bit;
            cin >> bit;
            cnt[bit]++;
        }
        for (ll i=max(0ll,k-cnt[1]);i<=min(k/2,cnt[0]);i++){
            mll nv=f[cnt[0]]*inv[i]*inv[cnt[0]-i]*f[cnt[1]]*inv[k-i]*inv[cnt[1]-(k-i)];
            sum+=nv;
            // cout << i << " => " << nv << ' ' << mll(f[cnt[0]]*inv[i]*inv[cnt[0]-i]).v << ' ' << mll(f[cnt[1]]*inv[k-i]*inv[cnt[1]-(k-i)]).v << '\n';
        }
        cout << sum << '\n';
    }
}