#include <bits/stdc++.h>
using namespace std;
// #define __int128_t long long

using lll=__int128_t;
using ll = long long;
using db = double;
const int N=1005;
ll MX=1e18;

struct line{
    db m=1,c=0;
    line(db m,db c):m(m),c(c){};
    line():m(1),c(0){};
    db tud (line l){
        if (m==l.m) return 0;
        return (l.c-c)/(m-l.m);
    }
    db y(db x){
        return m*x+c;
    }
};


ll n;
db ar[N][3];

ll solve (){
    ll val[N],id[N],di[N],win[N];
    line l[N];
    vector<ll> lid;
    map <pair<db,ll>,ll> px1;
    map<pair<db,db>,vector<tuple<db,ll,ll>>> px2;
    ll cnt=1,ans=1e9;
    bool db1=0,db2=0;
    db g1=ar[1][0],s1=ar[1][1],b1=ar[1][2];
    for (ll i=2;i<=n;i++){
        db ng,ns,nb;
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
                db nx=((s1-ns)/(ng-g1));
                tmp=(g1*(nx+1)+s1<ng*(nx+1)+ns);
                if (nx<db(1)){
                    if (tmp) cnt++;
                }
                else{
                    if (!tmp) cnt++;
                    px1[{nx,(tmp?1:-1)}]++;
                }
            }
        }
        else{
            db nm=((g1-ng)/(nb-b1)),nc=((s1-ns)/(nb-b1));
            line nl(nm,nc);
            db ny=max(db(1),nc+1);
            tmp=((s1/ny)+db(b1)<(ns/ny)+db(nb));
            l[i]=nl;
            win[i]=(tmp?1:-1);
            lid.emplace_back(i);
        }
    }
    l[n+1]=line(0,1);
    lid.emplace_back(n+1);
    px1[{db(1),0}]++;
    for (int ii=0;ii<lid.size();ii++){
        for (int jj=0;jj<ii;jj++){
            ll i=lid[ii],j=lid[jj];
            if (l[i].m==l[j].m || l[i].tud(l[j])<db(1)) continue;
            db nx=l[i].tud(l[j]);
            px2[{nx,l[i].y(nx)}].emplace_back(l[i].m,win[i],i);
            px2[{nx,l[j].y(nx)}].emplace_back(l[j].m,win[j],j);
        }
    }
    ll nc=0;
    vector <tuple<db,ll,ll>> vec;
    for (auto i:lid) {
        if (win[i]==-1) nc++;
        vec.emplace_back(l[i].y(1),win[i],i);
    }
    val[0]=nc;
    sort(vec.begin(),vec.end());
    while (!px1.empty() && px1.begin()->first<make_pair(db(1),1ll)){
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
            vector <tuple<db,ll>> nv2;
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
        vector <tuple<db,ll>> nv2;
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
    for (int i=1;i<=n;i++){
        cin >> ar[i][0] >> ar[i][1] >> ar[i][2];
    }
    cout << solve();
}