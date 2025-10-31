#include <bits/stdc++.h>
using namespace std;
#define __int128_t long long

using lll=__int128_t;
using ll=long long;
lll MX=1e18;
bool db1=0,db2=0;

struct frac{
    lll num=1,den=1;
    frac(ll n,ll d):num(n),den(d){lw();}
    frac(ll n): num(n),den(1){}
    frac():num(0),den(1){}
    void lw(){
        lll gcd=__gcd(num,den);
        num/=gcd;
        den/=gcd;
        if (den<0) num*=-1,den*=-1;
        if (num>MX || den>MX || num<(-MX) || den<(-MX)){
            // cout << "!!\n";
            exit(1);
        }
    }
    bool operator < (const frac &o) const { 
        lll gcd=max(__gcd(den,o.den),(__int128_t)1);
        return o.den/gcd*num < den/gcd*o.num; 
    }
    bool operator > (const frac &o) const { 
        lll gcd=max(__gcd(den,o.den),(__int128_t)1);
        return o.den/gcd*num > den/gcd*o.num;
    }
    bool operator == (const frac &o) const { return !(*this<o || *this>o);}
    bool operator <= (const frac &o) const { return !(*this>o);}
    bool operator >= (const frac &o) const { return !(*this<o);}
    frac operator += (const frac &o){
        lll gcd=__gcd(den,o.den);
        num=num*(o.den/gcd)+o.num*(den/gcd);
        den*=o.den/gcd;
        lw();
        return *this;
    }
    frac operator -= (const frac &o){
        lll gcd=__gcd(den,o.den);
        num=num*(o.den/gcd)-o.num*(den/gcd);
        den*=o.den/gcd;
        lw();
        return *this;
    }
    frac operator *= (const frac &o){
        lll g1=max(__gcd(num,o.den),(__int128_t)1),g2=max(__gcd(den,o.num),(__int128_t)1);
        num/=g1;
        den/=g2;
        num*=o.num/g2;
        den*=o.den/g1;
        lw();
        return *this;
    }
    frac operator /= (const frac &o){
        lll g1=max(__gcd(num,o.num),(__int128_t)1),g2=max(__gcd(den,o.den),(__int128_t)1);
        num/=g1;
        den/=g2;
        num*=o.den/g2;
        den*=o.num/g1;
        lw();
        return *this;
    }
    friend frac operator + (const frac &lhs,const frac &rhs){return frac(lhs)+=rhs;}
    friend frac operator - (const frac &lhs,const frac &rhs){return frac(lhs)-=rhs;}
    friend frac operator * (const frac &lhs,const frac &rhs){return frac(lhs)*=rhs;}
    friend frac operator / (const frac &lhs,const frac &rhs){return frac(lhs)/=rhs;}
    double db(){
        return double(num)/double(den);
    }
};

struct line{
    frac m=1,c=0;
    line(frac m,frac c):m(m),c(c){};
    frac tud (line l){
        return (l.c-c)/(m-l.m);
    }
    frac y(frac x){
        return (m*x)+c;
    }
};

const ll N=1005;
vector<pair<line,bool>> l;
map <pair<frac,ll>,ll> px,py;
ll ar[N][3];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,cnt=1,ans=1e9;
    ll g1,s1,b1;
    frac tx(1),ty(1);
    cin >> n;
    for (int i=1;i<=n;i++) cin >> ar[i][0] >> ar[i][1] >> ar[i][2];
    g1=ar[1][0]; s1=ar[1][1]; b1=ar[1][2];
    frac tf(1);
    for (ll i=2;i<=n;i++){
        ll ng,ns,nb;
        bool tmp;
        ng=ar[i][0]; ns=ar[i][1]; nb=ar[i][2];
        if (ng<=g1 && ns<=s1 && nb<=b1) continue;
        if (ng>=g1 && ns>=s1 && nb>=b1){
            cnt++;
            continue;
        }
        if (nb==b1){
            if (ng==g1) cnt+=ns>s1;
            else{
                frac nx((s1-ns),(ng-g1));
                tmp=(g1*(nx+1)+s1<ng*(nx+1)+ns);
                if (nx<frac(1)){
                    if (tmp) cnt++;
                }
                else{
                    if (!tmp) cnt++;
                    px[{nx,(tmp?1:-1)}]++;
                }
                if (db1) printf("\n | %d --> %d/%d (%f) %d",i,nx.num,nx.den,nx.db(),tmp);
            }
        }
        else{
            frac nm((g1-ng),(nb-b1));
            line nl(nm,frac((s1-ns),(nb-b1)));
            frac ny=nl.y(1)+frac(1);
            tmp=(frac(g1+s1)/ny+frac(b1)<frac(ng+ns)/ny+frac(nb));
            l.emplace_back(nl,tmp);
            if (db1) printf("\n / %d --> %d/%d (%f) %d/%d (%f) %d",i,nl.m.num,nl.m.den,nl.m.db(),nl.c.num,nl.c.den,nl.c.db(),tmp);
        }
    }
    for (auto [l1,k1]:l){
        for (auto [l2,k2]:l){
            if (l1.m==l2.m || l1.tud(l2)<frac(1)) continue;
            frac nx=l1.tud(l2);
            px[{nx,0}]++;
            // if (db2) if (l1.tud(l2).den==0) printf(" \n --> %d/%d x + %d/%d = %d/%d x + %d/%d : x = %d/%d",l1.m.num,l1.m.den,l1.c.num,l1.c.den,l2.m.num,l2.m.den,l2.c.num,l2.c.den,nx.num,nx.den);
        }
    }
    px[{frac(1),0}]++;
    px[{frac(2000),0}]++;
    for (auto [np,nt]:px){
        if (db1) printf("\n");
        auto [nx,ns]=np;
        if (ns==-1) cnt-=nt;
        ll nc=cnt;
        for (auto [nl,nk]:l){
            if (nl.y(nx)<=frac(0)){
                if (nk) nc++;
            }
            else if (nl.y(nx)>frac(1)){
                if (!nk) nc++;
            }
            else{
                if (!nk) nc++;
                py[{nl.y(nx),(nk?1:-1)}]++;
            }
        }
        py[{frac(1),0}]++;
        for (auto [mp,mt]:py){
            auto [my,ms]=mp;
            if (ms==-1) nc-=mt;
            if (db2) printf(" => %d/%d (%f) %d %d : %d/%d (%f) %d %d = %d\n",nx.num,nx.den,nx.db(),ns,nt,my.den,my.num,(1/my).db(),ms,mt,nc);
            ll ans2=1;
            for (int i=2;i<=n;i++){
                frac v1=g1/my*nx+s1/my+b1,nv=ar[i][0]/my*nx+ar[i][1]/my+ar[i][2];
                // if (db2) printf(" : %f %f\n",v1.db(),nv.db());
                if (v1<nv) ans2++;
                // if (ans2==1 && i==n) cout << "\t => " << nx.db() << ' ' << my.db() << '\n';
            }
            if (ans>ans2) tx=nx,ty=my;
            ans=min(ans,ans2);
            if (ms==1) nc+=mt;
        }
        py.clear();
        if (ns==1) cnt+=nt;
    }
    cout << "\n tx = " << ll(tx.num) << '/' << ll(tx.den) << " ("<< tx.db() << ")" << " ty = " << ll(ty.num) << '/' << ll(ty.den) << " (" << (ty).db() << ")\n";
    cout << ans;
}