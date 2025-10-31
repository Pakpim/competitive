#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5,M=998244353;
ll p[N],c[N],cnt[N],par[N];
deque<pair<ll,ll>> dql[N],dqr[N];
vector<tuple<ll,ll,ll>> v;

int root (int nn){
    if (!par[nn]) return nn;
    return par[nn]=root(par[nn]);
}

void uni (int nu,int nv){
    nu=root(nu);
    nv=root(nv);
    if (nu==nv) return;
    if (dql[nu].size()+dqr[nu].size()>dql[nv].size()+dqr[nv].size()) swap(nu,nv);
    par[nu]=nv;

}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll n,ans=1;
        cin >> n;
        for (int i=1;i<=n;i++) par[i]=0,dql[i].clear(),dqr[i].clear();
        for (int i=1;i<=n;i++) cin >> p[i];
        for (int i=1;i<=n;i++) cin >> c[i];
        for (int i=1;i<=n;i++){
            v.emplace_back(p[i],c[i],i);
        }
        sort(v.begin(),v.end());
        for (auto [np,nc,ni]:v){
            
        }
        cout << ans << '\n';
    }
}