#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using pi=pair<ll,ll>;
using ti=tuple<ll,ll,ll>;
const ll N=3e5+5;
ll ans,fw[N],fw2[N],sz[N],hv[N],h[N];
vector<ll> g[N];

void up (ll p,ll v){
    // cout << "up ->" << p << ' ' << v << '\n';
    ll tp=p*v;
    while (p<N){
        fw[p]+=v;
        fw2[p]+=tp;
        p+=p&-p;
    }
    return;
}

pi qu (ll p){
    pi re={0,0};
    while (p){
        re.first+=fw[p];
        re.second+=fw2[p];
        p-=p&-p;
    }
    return re;
}

void up2 (ll nn,ll np,ll v){
    for (auto e:g[nn]) if (e!=np) up2(e,nn,v);
    // cout << nn << ' ';
    up(h[nn],v);
}

void cal (ll nn,ll np,ll hr){
    auto [mx1,mx2]=qu(N-1);
    auto [v1,v2]=qu(h[nn]-1);
    ll tmp=mx1-v1;
    ans+=tmp*((h[nn]-hr)*2-1);
    ans+=2*v2-2*(hr*v1)-v1;
    // cout << nn << ' ' << np << " => " << tmp << ' ' << h[nn] << ' ' << hr << ' ' << qu(N-1) << ' ' << qu(h[nn]-1) << " = " << ans << '\n';
    for (auto e:g[nn]) if (e!=np) cal(e,nn,hr);
}

void dfs2 (ll nn,ll np){
    for (auto e:g[nn]) if (e!=np && e!=hv[nn]){
        dfs2(e,nn);
        up2(e,nn,-1);
    }
    if (hv[nn]) {
        dfs2(hv[nn],nn);
    }
    for (auto e:g[nn]) if (e!=np && e!=hv[nn]){
        cal(e,nn,h[nn]);
        up2(e,nn,1);
    }
    // cout << nn << ' ';
    up(h[nn],1);
}

void dfs (ll nn,ll np){
    h[nn]=h[np]+1;
    sz[nn]=1;
    ll mx=0;
    for (auto e:g[nn]) if (e!=np) {
        dfs(e,nn);
        sz[nn]+=sz[e];
        if (mx<sz[e]){
            mx=sz[e];
            hv[nn]=e;
        }
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        ans=0;
        for (ll i=1;i<n;i++){
            ll u,v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(1,0);
        dfs2(1,0);
        up2(1,0,-1);
        for (ll i=0;i<=n+1;i++){
            g[i].clear();
            sz[i]=hv[i]=h[i]=0;
        }
        cout << ans << '\n';
    }
}