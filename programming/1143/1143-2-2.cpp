#include <bits/stdc++.h>
using namespace std;

using lll=__int128_t;
using ll = long long;
using db = double;
ll MX=1e18;

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
            cout << "!!\n";
            // exit(1);
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
    frac operator += (const frac &o){
        lll gcd=max(__gcd(den,o.den),(__int128_t)1);
        num=num*(o.den/gcd)+o.num*(den/gcd);
        den*=o.den;
        lw();
        return *this;
    }
    frac operator -= (const frac &o){
        lll gcd=max(__gcd(den,o.den),(__int128_t)1);
        num=num*(o.den/gcd)-o.num*(den/gcd);
        den*=o.den;
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

struct line1{
    db m=1,c=0;
    line1(db m,db c):m(m),c(c){};
    db tud (line1 l){
        if (m==l.m) return 0;
        return (l.c-c)/(m-l.m);
    }
    db y(db x){
        return m*x+c;
    }
};

struct line2{
    frac m=1,c=0;
    line2(frac m,frac c):m(m),c(c){};
    frac tud (line2 l){
        if (m==l.m) return 0;
        return (l.c-c)/(m-l.m);
    }
    frac y(frac x){
        return m*x+c;
    }
};

const int N=1005;
ll ar[N][3];
ll n;
ll g1,s1,b1;
frac tx,ty;

ll solve1 (){
    int ans=n;
    
    return ans;
}

ll solve2(){
    vector<pair<line2,bool>> l;
    map <pair<frac,ll>,ll> px,py;
    ll cnt=1,ans=1e9;
    for (ll i=2;i<=n;i++){
        ll ng,ns,nb;
        bool tmp;
        ng=ar[i][0];
        ns=ar[i][1];
        nb=ar[i][2];
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
                    px[{nx,tmp}]++;
                }
                // printf("\n | %d --> %d/%d %d",i,nx.num,nx.den,tmp);
            }
        }
        else{
            line2 nl(frac((g1-ng),(nb-b1)),frac((s1-ns),(nb-b1)));
            frac ny=nl.y(1)+frac(1);
            tmp=(frac(g1+s1)/ny+frac(b1)<frac(ng+ns)/ny+frac(nb));
            l.emplace_back(nl,tmp);
            // printf("\n / %d --> %d/%d %d/%d %d",i,nl.m.num,nl.m.den,nl.c.num,nl.c.den,tmp);
        }
    }
    for (auto [l1,k1]:l){
        for (auto [l2,k2]:l){
            if (l1.m==l2.m || l1.tud(l2)<frac(1)) continue;
            px[{l1.tud(l2),-1}]++;
        }
    }
    px[{frac(1),-1}]++;
    for (auto [np,nt]:px){
        // printf("\n");
        auto [nx,ns]=np;
        if (ns==0) cnt-=nt;
        ll nc=cnt;
        for (auto [nl,nk]:l){
            if (nl.y(nx)<frac(0)){
                if (nk) nc++;
            }
            else if (nl.y(nx)>frac(1)){
                if (!nk) nc++;
            }
            else{
                if (!nk) nc++;
                py[{nl.y(nx),nk}]++;
            }
        }
        py[{frac(1),-1}]++;
        py[{frac(0),-1}]++;
        for (auto [mp,mt]:py){
            auto [my,ms]=mp;
            if (ms==0) nc-=mt;
            // printf(" => %d/%d %d %d : %d/%d %d %d = %d\n",nx.num,nx.den,ns,nt,my.num,my.den,ms,mt,nc);
            if (ans>nc){
                tx=nx;
                ty=my;
            }
            ans=min(ans,nc);
            if (ms==1) nc+=mt;
        }
        py.clear();
        if (ns==1) cnt+=nt;
    }
    return ans;
}

ll check2(frac nx,frac ny){
    ll ans=1;
    for (int i=2;i<=n;i++){
        frac v1=g1/ty*tx+s1/ty+b1,nv=ar[i][0]/ty*tx+ar[i][1]/ty+ar[i][2];
        if (v1<nv) {
            // cout << "! " << v1.db() << ' ' << nv.db() << '\n';
            ans++;
        }
    }
    return ans;
}

int main(){
    int cnt=0,K=401,MN=30;
    mt19937 rnd;
    do{
        cnt++;
        n=rnd()%MN;
        g1=rnd()%K;
        s1=rnd()%K;
        b1=rnd()%K;
        for (int i=2;i<=n;i++){
            ar[i][0]=rnd()%K;
            ar[i][1]=rnd()%K;
            ar[i][2]=rnd()%K;
        }
        cout << cnt << '\n';
    }while(solve2()==check2(tx,ty) && cnt<100);
    cout << n << '\n' << g1 << ' ' << s1 << ' ' << b1 << '\n';
    for (int i=2;i<=n;i++){
        cout << ar[i][0] << ' ' << ar[i][1] << ' ' << ar[i][2] << '\n';
    }
    cout << solve2() << '\n';
    cout << check2(tx,ty) << '\n';
}