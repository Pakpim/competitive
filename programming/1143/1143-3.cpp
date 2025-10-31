#include <bits/stdc++.h>
using namespace std;
// #define __int128_t long long

using lll=__int128_t;
using ll = long long;
using db = double;
const int N=1005;
ll MX=1e18;

struct frac{
    lll num=1,den=1;
    frac(ll n,ll d):num(n),den(d){init();}
    frac(ll n): num(n),den(1){}
    frac():num(0),den(1){}
    void init(){
        lll gcd=__gcd(num,den);
        num/=gcd; den/=gcd;
        if (den<0) num*=-1,den*=-1;
        if (num>MX || den>MX || num<(-MX) || den<(-MX)){
            exit(1);
        }
    }
    bool operator < (const frac &o) const { return o.den*num < den*o.num; }
    bool operator > (const frac &o) const { return o.den*num > den*o.num; }
    bool operator == (const frac &o) const { return !(*this<o || *this>o);}
    bool operator <= (const frac &o) const { return !(*this>o);}
    bool operator >= (const frac &o) const { return !(*this<o);}
    frac operator += (const frac &o){
        num=num*o.den+o.num*den;
        den*=o.den;
        init();
        return *this;
    }
    frac operator -= (const frac &o){
        num=num*o.den-o.num*den;
        den*=o.den;
        init();
        return *this;
    }
    frac operator *= (const frac &o){
        num*=o.num;
        den*=o.den;
        init();
        return *this;
    }
    frac operator /= (const frac &o){
        num*=o.den;
        den*=o.num;
        init();
        return *this;
    }
    friend frac operator + (const frac &lhs,const frac &rhs){return frac(lhs)+=rhs;}
    friend frac operator - (const frac &lhs,const frac &rhs){return frac(lhs)-=rhs;}
    friend frac operator * (const frac &lhs,const frac &rhs){return frac(lhs)*=rhs;}
    friend frac operator / (const frac &lhs,const frac &rhs){return frac(lhs)/=rhs;}
    double db(){ return double(num)/double(den);}
};

struct line{
    frac m=1,c=0;
    line(frac m,frac c):m(m),c(c){};
    line():m(1),c(0){};
    frac tud (line l){
        if (m==l.m) return 0;
        return (l.c-c)/(m-l.m);
    }
    frac y(frac x){ return m*x+c; }
}l[N];


ll n,ar[N][3],val[N],id[N],di[N],win[N];

ll solve (){
    vector<ll> lid;
    map <pair<frac,ll>,ll> px1;
    map<pair<frac,frac>,vector<tuple<frac,ll,ll>>> px2;
    ll cnt=1,ans=1e9;
    ll g1=ar[1][0],s1=ar[1][1],b1=ar[1][2];
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
                    px1[{nx,(tmp?1:-1)}]++;
                }
            }
        }
        else{
            frac nm((g1-ng),(nb-b1)),nc((s1-ns),(nb-b1));
            line nl(nm,nc);
            frac ny=max(frac(1),nc+1);
            tmp=((s1/ny)+frac(b1)<(ns/ny)+frac(nb));
            l[i]=nl;
            win[i]=(tmp?1:-1);
            lid.emplace_back(i);
        }
    }
    l[n+1]=line(0,1);
    lid.emplace_back(n+1);
    px1[{frac(1),0}]++;
    for (int ii=0;ii<lid.size();ii++){
        for (int jj=0;jj<ii;jj++){
            ll i=lid[ii],j=lid[jj];
            if (l[i].m==l[j].m || l[i].tud(l[j])<frac(1)) continue;
            frac nx=l[i].tud(l[j]);
            px2[{nx,l[i].y(nx)}].emplace_back(l[i].m,win[i],i);
            px2[{nx,l[j].y(nx)}].emplace_back(l[j].m,win[j],j);
        }
    }
    ll nc=0;
    vector <tuple<frac,ll,ll>> vec;
    for (auto i:lid) {
        if (win[i]==-1) nc++;
        vec.emplace_back(l[i].y(1),win[i],i);
    }
    val[0]=nc;
    sort(vec.begin(),vec.end());
    while (!px1.empty() && px1.begin()->first<make_pair(frac(1),1ll)){
        auto [np,nt]=*(px1.begin());
        auto [nx,ns]=np;
        cnt+=nt*ns;
        px1.erase(px1.begin());
    }
    for (ll i=1;i<=vec.size();i++){
        auto [ny,nw,ni]=vec[i-1];
        if (nw==-1) nc--;
        val[i]=nc;
        if (nw==1) nc++;
        id[i]=ni;
        di[ni]=i;
        if (ny>0 && ny<=1) ans=min(ans,val[i]+cnt);
    }
    for (auto [np,nv]:px2){
        auto [nx,ny]=np;
        while (!px1.empty() && px1.begin()->first<make_pair(nx,1ll)){
            auto [np2,nt]=*(px1.begin());
            auto [nx2,ns]=np2;
            cnt+=nt*ns;
            vector <tuple<frac,ll>> nv2;
            ll nc2=0;
            for (int i=2;i<=n+1;i++){
                if (l[i].y(nx2)<=0) nc2+=(win[i]==1);
                else {
                    nc2+=(win[i]==-1);
                    if (l[i].y(nx2)<=1) nv2.emplace_back(l[i].y(nx2),win[i]);
                }
            }
            sort(nv2.begin(),nv2.end());
            for (auto [ny2,nw2]:nv2){
                if (nw2==-1) nc2--;
                ans=min(ans,nc2+cnt);
                if (nw2==1) nc2++;
            }
            px1.erase(px1.begin());
        }
        sort(nv.begin(),nv.end());
        ll pl=n+1;
        for (ll i=0;i<nv.size();i++){
            auto [nm,nw,ni]=nv[i];
            if (i>0){
                auto [bm,bw,bi]=nv[i-1];
                if (bi==ni) continue;
            }
            pl=min(pl,di[ni]);
        }
        nc=val[pl-1];
        ll npos=pl;
        for (ll i=0;i<nv.size();i++){
            auto [nm,nw,ni]=nv[i];
            if (i>0){
                auto [bm,bw,bi]=nv[i-1];
                if (bi==ni) continue;
            }
            id[npos]=ni;
            di[ni]=npos;
            if (win[id[npos-1]]==1) nc++;
            if (nw==-1) nc--;
            val[npos]=nc;
            npos++;
        }
        if (ny>0 && ny<=1){
            nc=val[pl-1]+(win[id[pl-1]]==1);
            for (ll i=0;i<nv.size();i++) {
                auto [nm,nw,ni]=nv[i];
                if (i>0){
                    auto [bm,bw,bi]=nv[i-1];
                    if (bi==ni) continue;
                }
                if (nw==-1) nc--;
            }
            ans=min(ans,cnt+nc);
        }
    }
    while (!px1.empty() ){
        auto [np2,nt]=*(px1.begin());
        auto [nx2,ns]=np2;
        cnt+=nt*ns;
        vector <tuple<frac,ll>> nv2;
        ll nc2=0;
        for (int i=2;i<=n+1;i++){
            if (l[i].y(nx2)<=0) nc2+=(win[i]==1);
            else {
                nc2+=(win[i]==-1);
                if (l[i].y(nx2)<=1) nv2.emplace_back(l[i].y(nx2),win[i]);
            }
        }
        sort(nv2.begin(),nv2.end());
        for (auto [ny2,nw2]:nv2){
            if (nw2==-1) nc2--;
            ans=min(ans,nc2+cnt);
            if (nw2==1) nc2++;
        }
        px1.erase(px1.begin());
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++) cin >> ar[i][0] >> ar[i][1] >> ar[i][2];
    cout << solve();
}