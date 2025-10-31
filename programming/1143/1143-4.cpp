#include <bits/stdc++.h>
using namespace std;
// #define __int128_t long long

using lll=__int128_t;
using ll = long long;
using db = double;
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
};

const int N=1005;
ll ar[N][3],n;

ll cal (frac nx,frac ny){
    ll re=1;
    for (int i=2;i<=n;i++){
        frac v1=ar[1][0]/ny*nx+ar[1][1]/ny+ar[1][2],nv=ar[i][0]/ny*nx+ar[i][1]/ny+ar[i][2];
        if (v1<nv) re++;
    }
    return re;
}

ll solve1 (){
    ll val[N],id[N],di[N],win[N];
    line l[N];
    vector<ll> lid;
    map <pair<frac,ll>,ll> px1;
    map<pair<frac,frac>,vector<tuple<frac,ll,ll>>> px2;
    vector <tuple<frac,ll,ll>> vec;
    ll cnt=1,ans=1e9;
    bool db1=0,db2=0;
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
                if (db1) printf("\n | %d --> %d/%d (%f) %d\n",i,nx.num,nx.den,nx.db(),tmp);
            }
        }
        else{
            frac nm((g1-ng),(nb-b1)),nc((s1-ns),(nb-b1));
            line nl(nm,nc);
            frac ny=max(frac(1),nc+1);
            if (db1) printf(" %f : %f %f",ny.db(),((s1/ny)+frac(b1)).db(),((ns/ny)+frac(nb)).db());
            tmp=((s1/ny)+frac(b1)<(ns/ny)+frac(nb));
            l[i]=nl;
            win[i]=(tmp?1:-1);
            lid.emplace_back(i);
            if (db1) printf("\n / %d --> %d/%d (%f) %d/%d (%f) %d\n",i,nl.m.num,nl.m.den,nl.m.db(),nl.c.num,nl.c.den,nl.c.db(),tmp);
        }
    }
    l[0]=line(0,1);
    lid.emplace_back(0);
    px1[{frac(1),0}]++;
    for (int ii=0;ii<lid.size();ii++){
        for (int jj=0;jj<ii;jj++){
            ll i=lid[ii],j=lid[jj];
            if (l[i].m==l[j].m || l[i].tud(l[j])<frac(1)) continue;
            frac nx=l[i].tud(l[j]);
            px2[{nx,l[i].y(nx)}].emplace_back(l[i].m,win[i],i);
            px2[{nx,l[j].y(nx)}].emplace_back(l[j].m,win[j],j);
            // if (db2) if (l1.tud(l2).den==0) printf(" \n --> %d/%d x + %d/%d = %d/%d x + %d/%d : x = %d/%d",l1.m.num,l1.m.den,l1.c.num,l1.c.den,l2.m.num,l2.m.den,l2.c.num,l2.c.den,nx.num,nx.den);
        }
    }
    ll nc=0;
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
        if (ny>0 && ny<=1){
            if (db2) cout << " 1 => " << ny.db() << ' ' << nw << ' ' << ni << ' ' << val[i] << ' ' << cnt << '\n';
            ans=min(ans,val[i]+cnt);
        }
    }
    if (db2){
        for (int i=1;i<=vec.size();i++) cout << val[i] << ' ';
        cout << '\n';
        for (int i=1;i<=vec.size();i++) cout << id[i] << ' ';
        cout << '\n';
    }
    for (auto [np,nv]:px2){
        auto [nx,ny]=np;
        while (!px1.empty() && px1.begin()->first<make_pair(nx,1ll)){
            auto [np2,nt]=*(px1.begin());
            auto [nx2,ns]=np2;
            cnt+=nt*ns;
            vector <tuple<frac,ll>> nv2;
            ll nc2=0;
            for (int i=0;i<=n;i++){
                if (i==1) continue;
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
        if (db2){
            cout << "\t" << nx.db() << ' ' << ny.db() << '\n';
            for (ll i=0;i<nv.size();i++){
                auto [nm,nw,ni]=nv[i];
                cout << '\t' << i << " --> " << nm.db() << ' ' << nw << ' ' << ni << ' ' << di[ni] << '\n';
            }
        }
        ll pl=n+1;
        vector<ll> tmp;
        for (ll i=0;i<nv.size();i++){
            auto [nm,nw,ni]=nv[i];
            if (i>0){
                auto [bm,bw,bi]=nv[i-1];
                if (bi==ni) continue;
            }
            tmp.emplace_back(di[ni]);
            pl=min(pl,di[ni]);
        }
        sort(tmp.begin(),tmp.end());
        if (db2){
            cout << "\n => ";
            for (auto e:tmp) cout << e << ' ';
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
            if (db2) cout << nc << ' ';
            for (ll i=0;i<nv.size();i++) {
                auto [nm,nw,ni]=nv[i];
                if (i>0){
                    auto [bm,bw,bi]=nv[i-1];
                    if (bi==ni) continue;
                }
                if (nw==-1) nc--;
                if (db2) cout << nc << ' ';
            }
            if (db2) cout << "\t ---> " << nc + cnt <<' ' << nc << ' ' << cnt << ' ' << pl-1 << ' ' << val[pl-1] << ' ' << id[pl-1] << ' ' << win[id[pl-1]] << '\n';
            ans=min(ans,cnt+nc);
        }
        if (db2){
            for (int i=1;i<=vec.size();i++) cout << val[i] << ' ';
            cout << '\n';
            for (int i=1;i<=vec.size();i++) cout << id[i] << ' ';
            cout << '\n';
        }
    }
    while (!px1.empty() ){
        auto [np2,nt]=*(px1.begin());
        auto [nx2,ns]=np2;
        cnt+=nt*ns;
        vector <tuple<frac,ll>> nv2;
        ll nc2=0;
        for (int i=0;i<=n;i++){
            if (i==1) continue;
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

ll solve2(){
    frac tx,ty;
    vector<pair<line,bool>> l;
    map <pair<frac,ll>,ll> px,py;
    ll cnt=1,ans=1e9;
    bool db1=0,db2=0,db3=0;
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
                    px[{nx,(tmp?1:-1)}]++;
                    // px.emplace_back(nx,(tmp?1:-1));
                }
                if (db1) printf("\n | %d --> %d/%d (%f) %d\n",i,nx.num,nx.den,nx.db(),tmp);
            }
        }
        else{
            frac nm((g1-ng),(nb-b1)),nc((s1-ns),(nb-b1));
            line nl(nm,nc);
            // y=0 1/x=c
            frac ny=max(frac(1),nc+1);
            if (db1) printf(" %f : %f %f",ny.db(),((s1/ny)+frac(b1)).db(),((ns/ny)+frac(nb)).db());
            tmp=((s1/ny)+frac(b1)<(ns/ny)+frac(nb));
            l.emplace_back(nl,tmp);
            if (db1) printf("\n / %d --> %d/%d (%f) %d/%d (%f) %d\n",i,nl.m.num,nl.m.den,nl.m.db(),nl.c.num,nl.c.den,nl.c.db(),tmp);
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
    // for (int i=0;i<n;i++) for (int j=0;j<n;j++) px[{frac(i*j),0}]++;
    px[{frac(1),0}]++;
    px[{frac(2000),0}]++;
    for (auto [np,nt]:px){
        if (db2) printf("\n");
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
            if (db2) printf(" => %d/%d (%f) %d %d : %d/%d (%f) %d %d = %d\n",nx.num,nx.den,nx.db(),ns,nt,my.num,my.den,(my).db(),ms,mt,nc);
            if (ans>nc) tx=nx,ty=my;
            ans=min(ans,nc);
            if (ms==1) nc+=mt;
        }
        py.clear();
        if (ns==1) cnt+=nt;
    }
    if (db3) cout << " 2 -> " << tx.db() << ' ' << ty.db() << " = " << cal(tx,ty) << '\n';
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i][0] >> ar[i][1] >> ar[i][2];
    }
    // if (solve1()>solve2()) exit(1);
    cout << solve1();
    // cout << solve1() <<  '\n';
    // cout << solve2();
    // int cnt=0,K=100,MN=500,T=100;
    // mt19937 rnd;
    // do{
    //     cnt++;
    //     n=rnd()%MN+2;
    //     for (int i=1;i<=n;i++){
    //         ar[i][0]=rnd()%K;
    //         ar[i][1]=rnd()%K;
    //         ar[i][2]=rnd()%K;
    //     }
    //     cout << " - " << cnt << '\n';
    //     // cout << n << '\n';
    //     // for (int i=1;i<=n;i++){
    //     //     cout << ar[i][0] << ' ' << ar[i][1] << ' ' << ar[i][2] << '\n';
    //     // }
    //     // cout << '\n' << solve1() ;
    //     // cout << '\n' << solve2() ;
    // }while(solve1()==solve2() && cnt<T);
    // if (cnt!=T){
    //     cout << n << '\n';
    //     for (int i=1;i<=n;i++){
    //         cout << ar[i][0] << ' ' << ar[i][1] << ' ' << ar[i][2] << '\n';
    //     }
    //     cout << '\n' << solve1() ;
    //     cout << '\n' << solve2() ;
    // }
    // else cout << "ok";
    // if (solve1()<solve2()) exit(1);
}

/*
6
75 57 23
63 9 55
85 42 35
81 30 20
56 38 51
74 70 8

1
2
*/