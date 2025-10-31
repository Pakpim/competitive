#include <bits/stdc++.h>
using namespace std;

using ll=long long;
ll M = 1e9+7;
ll n,m,q;


#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-03-17
 * Description: modular arithmetic operators using Montgomery space
 */

template<uint32_t mod,uint32_t root=0>
struct MontgomeryModInt{
    using mint = MontgomeryModInt;
    using i32 = int32_t;
    using u32 = uint32_t;
    using u64 = uint64_t;

    static constexpr u32 get_r(){
        u32 res=1;
        for(i32 i=0;i<5;i++)res*=2-mod*res;
        return res;
    }

    static const u32 r=get_r();
    static const u32 n2=-u64(mod)%mod;
    static_assert(mod<(1<<30));
    static_assert((mod&1)==1);
    static_assert(r*mod==1);

    u32 x;

    constexpr MontgomeryModInt():x(0){}
    constexpr MontgomeryModInt(const int64_t &v):x(reduce(u64(v%mod+mod)*n2)){}

    static constexpr u32 get_mod(){return mod;}
    static constexpr mint get_root(){return mint(root);}
    explicit constexpr operator ll()const{return val();}

    static constexpr u32 reduce(const u64 &v){
        return (v+u64(u32(v)*u32(-r))*mod)>>32;
    }

    constexpr u32 val()const{
        u32 res=reduce(x);
        return res>=mod?res-mod:res;
    }

    constexpr mint inv()const{
        int a=val(),b=mod,u=1,v=0,q=0;
        while(b>0){
            q=a/b;
            a-=q*b;
            u-=q*v;
            swap(a,b);
            swap(u,v);
        }
        return mint(u);
    }

    constexpr mint &operator+=(const mint &rhs){
        if(i32(x+=rhs.x-2*mod)<0)x+=2*mod;
        return *this;
    }
    constexpr mint &operator-=(const mint &rhs){
        if(i32(x-=rhs.x)<0)x+=2*mod;
        return *this;
    }
    constexpr mint &operator*=(const mint &rhs){
        x=reduce(u64(x)*rhs.x);
        return *this;
    }
    constexpr mint &operator/=(const mint &rhs){
        return *this*=rhs.inv();
    }

    constexpr mint &operator++(){return *this+=mint(1);}
    constexpr mint &operator--(){return *this-=mint(1);}
    constexpr mint operator++(int){
        mint res=*this;
        return *this+=mint(1),res;
    }
    constexpr mint operator--(int){
        mint res=*this;
        return *this-=mint(1),res;
    }

    constexpr mint operator-()const{return mint()-mint(*this);};
    constexpr mint operator+()const{return mint(*this);};

    friend constexpr mint operator+(const mint &lhs,const mint &rhs){return mint(lhs)+=rhs;}
    friend constexpr mint operator-(const mint &lhs,const mint &rhs){return mint(lhs)-=rhs;}
    friend constexpr mint operator*(const mint &lhs,const mint &rhs){return mint(lhs)*=rhs;}
    friend constexpr mint operator/(const mint &lhs,const mint &rhs){return mint(lhs)/=rhs;}
    friend constexpr bool operator==(const mint &lhs,const mint &rhs){
        return (lhs.x>=mod?lhs.x-mod:lhs.x)==(rhs.x>=mod?rhs.x-mod:rhs.x);
    }
    friend constexpr bool operator!=(const mint &lhs,const mint &rhs){
        return (lhs.x>=mod?lhs.x-mod:lhs.x)!=(rhs.x>=mod?rhs.x-mod:rhs.x);
    }
    friend constexpr bool operator<(const mint &lhs,const mint &rhs){
        return (lhs.x>=mod?lhs.x-mod:lhs.x)<(rhs.x>=mod?rhs.x-mod:rhs.x); // for std::map
    }

    friend istream &operator>>(istream &is,mint &o){
        int64_t v;
        is >> v;
        o=mint(v);
        return is;
    }
    friend ostream &operator<<(ostream &os,const mint &o){
        return os << o.val();
    }
};
using mint998 = MontgomeryModInt<998244353,3>;
using mll = MontgomeryModInt<1000000007>;

// struct mll{
//     ll v;
//     mll(): v(0){}
//     mll(ll v): v(v%M){}
//     mll operator += (const mll &o){v = (o.v+v)%M; return *this;}
//     mll operator *= (const mll &o){v = (o.v*v)%M; return *this;}
//     mll operator = (const ll &o){v = o%M; return *this;}
//     friend mll operator + (const mll &lhs,const mll &rhs) {return mll(lhs)+=rhs;}
//     friend mll operator * (const mll &lhs,const mll &rhs) {return mll(lhs)*=rhs;}
//     friend istream &operator >> (istream &is,mll &o){
//         ll x;
//         is >> x;
//         o=mll(x);
//         return is;
//     }
//     friend ostream &operator << (ostream &os,mll &o){
//         return os<<o.v;
//     }
// };

const ll N=200;
struct mtx{
    ll d;
    array<array<mll,N>,N> v;
    mtx(){
        d=N;
        for (ll i=0;i<d;i++) {
            for (int j=0;j<d;j++) v[i][j]=0;
            v[i][i]=1;
        }
    };
    mtx(ll d):d(d){
        for (ll i=0;i<d;i++) {
            for (int j=0;j<d;j++) v[i][j]=0;
            v[i][i]=1;
        }
    }
    mtx(vector<vector<mll>> v2): d(v2.size()) {
        for (int i=0;i<d;i++) for (int j=0;j<d;j++) v[i][j]=v2[i][j];
    }
    mtx operator *= (const mtx &o){
        array<array<mll,N>,N> tmp;
        for (ll i=0;i<d;i++){
            for (ll j=0;j<d;j++){
                tmp[i][j]=0;
                for (ll k=0;k<d;k++) tmp[i][j]+=v[i][k]*o.v[k][j];
            }
        }
        v=tmp;
        return *this;
    }
    friend mtx operator* (const mtx &lhs,const mtx &rhs){return mtx(lhs)*=rhs;}
}b[40];

ll s[N],t[N],k[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q;
    vector<vector<mll>> tmp (n,vector<mll> (n,0));
    while (m--){
        int u,v;
        cin >> u >> v;
        tmp[v-1][u-1]=1;
    }
    b[0]=mtx(tmp);
    for (int i=1;i<32;i++){
        b[i]=b[i-1]*b[i-1];
    }
    mll a[n],tmp2[n];
    while (q--){
        ll s,t,k;
        cin >> s >> t >> k;
        s--; t--;
        for (int i=0;i<n;i++) a[i]=0;
        a[s]=1;
        for (int l=0;1<<l<=k;l++){
            if (k&(1<<l)){
                for (int i=0;i<n;i++){
                    tmp2[i]=0;
                    for (int j=0;j<n;j++) tmp2[i]+=b[l].v[i][j]*a[j];
                }
                for (int i=0;i<n;i++) a[i]=tmp2[i];
            }
        }
        cout << a[t] << '\n';
    }
}

/*
3 4 1
1 2
2 3
3 1
2 1
1 3 1

*/