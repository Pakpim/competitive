#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using db=double;
using pll=pair<ll,ll>;
const ll N=1e5+5,K=1e4+5,M=105;
ll a[N],b[N],ans[K],c[N],d[N];
ll n,k,as,ac,bs,bc;
pll fw1[N],fw2[N];
vector<tuple<ll,ll,ll>> v[M];

void up (ll p,ll nv, ll nc,pll *fw){
    while (p<N){
        fw[p].first+=nv;
        fw[p].second+=nc;
        p+=p&-p;
    }
}

pair<ll,ll> qu (ll p,pll *fw){
    ll rs=0,rc=0;
    while (p){
        rs+=fw[p].first;
        rc+=fw[p].second;
        p-=p&-p;
    }
    return {rs,rc};
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (ll i=1;i<=n;i++) cin >> a[i];
    for (ll i=1;i<=n;i++) cin >> b[i];
    cin >> k;
    for (ll i=0;i<k;i++){
        ll x,y;
        cin >> x >> y;
        v[x/1000].emplace_back(y,x,i);
    }
    vector<pair<ll,ll>> sa,sb;
    for (ll i=1;i<=n;i++) sa.emplace_back(a[i],i);
    sort(sa.begin(),sa.end());
    for (ll i=0;i<n;i++) c[sa[i].second]=i+1;
    for (ll i=1;i<=n;i++) sb.emplace_back(b[i],i);
    sort(sb.begin(),sb.end());
    for (ll i=0;i<n;i++) d[sb[i].second]=i+1;
    ll px=0,py=0,sum=0;
    for (ll i=0;i*1000<=n;i++){
        sort(v[i].begin(),v[i].end());
        while (px<i*1000 && px<n){
            px++;
            up(c[px],a[px],1,fw1);
            as+=a[px]; ac++;
        }
        bs=0; bc=0; py=0; sum=0;
        for (ll i=1;i<=n;i++) fw2[i]={0,0};
        for (auto [y,x,idx]:v[i]){
            while (x<px){
                ll np=lower_bound(sb.begin(),sb.end(),make_pair(a[px],0ll))-sb.begin();
                auto [s1,c1]=qu(np,fw2);
                ll s2=bs-s1,c2=bc-c1;
                sum-=a[px]*c1-s1+s2-a[px]*c2;
                up(c[px],-a[px],-1,fw1);
                as-=a[px]; ac--;
                px--;
            }
            while (px<x){
                px++;
                ll np=lower_bound(sb.begin(),sb.end(),make_pair(a[px],0ll))-sb.begin();
                auto [s1,c1]=qu(np,fw2);
                ll s2=bs-s1,c2=bc-c1;
                sum+=a[px]*c1-s1+s2-a[px]*c2;
                up(c[px],a[px],1,fw1);
                as+=a[px]; ac++;
            }
            while (py<y){
                py++;
                ll np=lower_bound(sa.begin(),sa.end(),make_pair(b[py],0ll))-sa.begin();
                auto [s1,c1]=qu(np,fw1);
                ll s2=as-s1,c2=ac-c1;
                sum+=b[py]*c1-s1+s2-b[py]*c2;
                up(d[py],b[py],1,fw2);
                bs+=b[py]; bc++;
            }
            ans[idx]=sum;
        }
    }
    for (ll i=0;i<k;i++) cout << ans[i] << '\n';
}