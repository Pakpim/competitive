#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5;
ll n,l[N],r[N],h[N],par[N],ht[N],cnt,sum;
vector<tuple<ll,ll,ll,ll>> v;
deque<tuple<ll,ll,ll>> edge;

int root (int nn){
    if (par[nn]==-1) return nn;
    return par[nn]=root(par[nn]);
}

void uni (int a,int b,ll w){
    a=root(a); b=root(b);
    if (a==b) return;
    if (ht[a]>ht[b]) swap(a,b);
    par[a]=b;
    ht[b]=max(ht[b],ht[a]+1);
    cnt++;
    sum+=w;
    return;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> h[i] >> l[i] >> r[i];
    }
    for (int t=-1;t<2;t+=2){
        for (int t2=-1;t2<2;t2+=2){
            v.clear();
            for (int i=1;i<=n;i++){
                v.emplace_back(l[i]+h[i]*t, h[i]*t2,0,i);
                v.emplace_back(r[i]+h[i]*t,-h[i]*t2,1,i);
            }
            v.emplace_back(-2e9,0,0,0);
            set<pair<ll,ll>> s;
            sort(v.begin(),v.end());
            for(auto [np,nh,ns,ni]:v){
                // cout << " ? " << np << ' ' << nh << ' ' << ns << ' ' << ni << '\n';
                // for (auto [dh,di]:s) cout << dh << ' ' << di << '\n';
                auto it = s.upper_bound({h[ni]*t2,-1});
                if (it!=s.begin()){
                    auto it2=it; it2--;
                    auto [xh,xi] = *it2;
                    // cout << t << ' ' << t2 << " => " << ni << ' ' << xi << ' ' << abs(h[ni]-h[xi]) << '\n';
                    edge.emplace_back(abs(h[ni]-h[xi]),ni,xi);
                }
                if (!ns){
                    s.emplace(h[ni]*t2,ni);
                }
                else{
                    s.erase({h[ni]*t2,ni});
                }
                // cout << '\n';
            }
        }
    }
    sort(edge.begin(), edge.end());
    for (int i=0;i<=n;i++) par[i]=-1;
    while (cnt<n){
        auto [w,u,v]=edge.front();
        edge.pop_front();
        uni(u,v,w);
    }
    cout << sum;
}