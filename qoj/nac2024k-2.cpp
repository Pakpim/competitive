#include <bits/stdc++.h>
using namespace std;

// #define __int128_t long long

using lll = __int128_t;
using ll = long long;

struct frac{
    ll num=1,den=1;
    frac(ll n,ll d):num(n),den(d){init();}
    frac(ll n): num(n),den(1){}
    frac():num(0),den(1){}
    void init(){
        if (den<0) num*=-1,den*=-1;
        return;
        lll gcd=__gcd(num,den);
        num/=gcd; den/=gcd;
    }
    bool operator < (const frac &o) const { return lll(o.den)*num < lll(den)*o.num; }
    bool operator > (const frac &o) const { return lll(o.den)*num > lll(den)*o.num; }
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
    friend istream &operator>>(istream &is,frac &o){long long x; is >> x; o=frac(x); return is;}
    friend ostream &operator<<(ostream &os,frac o){return os << o.db();}
};

using db = double;
const int N = 3005;
ll x[N], y[N][2];
frac px[N*N*4],mn=0,w;
db ans;
int n,sum[N*2],ar[N*2],cnt,npos[N][2];
pair<int,int> npos2[N*2];
vector<pair<pair<frac,frac>,pair<int,int>>> vpos;
// map<pair<frac,frac>,vector<pair<ll,ll>>> pos;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll _w;
    cin >> n >> _w;
    w=_w;
    for (int i = 0; i < n; i++){
        ll _x,_y0,_y1;
        cin >> _x >> _y0 >> _y1;
        x[i]=_x; y[i][0]=_y0; y[i][1]=_y1;
    }
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            for (int k=0;k<2;k++){
                for (int h=0;h<2;h++){
                    if (x[i]==x[j] || y[i][k]==y[j][h]) continue;
                    frac nm(y[i][k]-y[j][h],x[i]-x[j]);
                    frac nx(x[i]*(y[i][k]-y[j][h])-y[i][k]*(x[i]-x[j]),y[i][k]-y[j][h]);
                    // frac nx=(x[i]-y[i][k]/nm);
                    if (nx.num>0) continue;
                    vpos.emplace_back(make_pair(nx,nm),make_pair(i,k));
                    vpos.emplace_back(make_pair(nx,nm),make_pair(j,h));
                    // pos[{nx,nm}].emplace_back(i,k);
                    // pos[{nx,nm}].emplace_back(j,h);
                    mn=min(mn,nx);
                }
            }
        }
    }
    vector<tuple<frac,ll,ll>> vecy;
    for (int i=0;i<n;i++){
        for (int j=0;j<2;j++){
            // frac nm=y[i][j]/(x[i]-mn);
            // frac ny=nm*(w-mn);
            vecy.emplace_back(y[i][j],j,i);
        }
    }
    sort(vecy.begin(),vecy.end());
    int ni=1;
    for (auto &[ny,ns,nn]:vecy){
        npos[nn][ns]=ni;
        npos2[ni]={nn,ns};
        ar[ni]= ns? -1:1;
        sum[ni]=sum[ni-1]+ar[ni];
        if (!sum[ni] && ni!=n*2) cnt++;
        ni++;
    }
    if (!cnt){
        cout << "-1";
        return 0;
    }
    ni=1;
    // vpos.emplace_back(make_pair(nx,nm),make_pair(i,k));
    sort(vpos.begin(),vpos.end());
    if(!vpos.empty()){
        px[ni++]=vpos[0].first.first;
    }
    for(int i=1;i<(int)vpos.size();i++){
        if(vpos[i].first!=vpos[i-1].first){
            px[ni++]=vpos[i].first.first;
        }
    }
    // ni=1;
    // for (auto &[nx,nvec]:pos) px[ni++]=nx.first;
    ni=1;
    // for (auto &[key,nvec]:pos){
    for(int li=0;li<(int)vpos.size();){

        int l=1e9,r=-1e9;
        auto [nx,nm]=vpos[li].first;
        int ri=li;
        while(ri+1<(int)vpos.size()&&vpos[ri+1].first==vpos[li].first)ri++;
        // for (auto [nn,ns]:nvec){
        for(;li<=ri;li++){
            auto [nn,ns]=vpos[li].second;
            l=min(l,npos[nn][ns]);
            r=max(r,npos[nn][ns]);
        }
        // if (r-l+1 != nvec.size()){
        //     cout << "!";
        //     exit(1);
        // }
        // if (n==3000) continue;
        for (int i=l;i<=r;i++) if (!sum[i] && i!=n*2) cnt--;
        for (int i=0;i<(r-l+1)/2;i++){
            auto [n1,s1]=npos2[l+i];
            auto [n2,s2]=npos2[r-i];
            swap(ar[l+i],ar[r-i]);
            swap(npos[n1][s1],npos[n2][s2]);
            swap(npos2[l+i],npos2[r-i]);
        }
        for (int i=l;i<=r;i++){
            sum[i]=sum[i-1]+ar[i];
            if (!sum[i] && i!=n*2) cnt++;
        }
        if (!cnt) {
            ans+=px[ni+1].db()-px[ni].db();
        }
        // cout << nx << ' ' << nm << " => " << cnt << ' ' << ans << '\n';
        ni++;
    }
    cout << fixed << setprecision(15) << ans;
}

/*
8 100 
50 22 24
31 9 11
89 38 40
95 44 45
43 17 19
2 0 2
85 37 39
6 1 3


-9.99996e+11 => 0,0 1,1  = -4.99998e+11 -9.99996e+11 4.99998e+11
-4.99998e+11 => 0,1 1,1  = -4.99998e+11 -4.99998e+11 499999
-4.99998e+11 => 0,0 1,0  = -3.33332e+11 -4.99998e+11 1.66666e+11
-3.33332e+11 => 0,1 1,0 666664333335.333374023437500

-9.99996e+11 1e-06 => 0 4.99998e+11
-4.99998e+11 2e-06 => 0 4.99999e+11
-4.99998e+11 2e-06 => 0 6.66664e+11
-3.33332e+11 3.00001e-06 => 1 6.66664e+11
*/