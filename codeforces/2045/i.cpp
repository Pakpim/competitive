#include <bits/stdc++.h>
#define lc i*2+1
#define rc i*2+2
#define mid (l+r)/2

using namespace std;

using ll=long long;
const ll N=3e5;
ll ar[N],n,m;
vector<ll> pos[N];
vector<ll> sg[N*4];

void build (int l=1,int r=n,int i=0){
    if (l>r) return;
    if (l==r){
        sg[i].emplace_back(ar[l]);
        return;
    }
    build(l,mid,lc);
    build(mid+1,r,rc);
    int pl=0,pr=0;
    while (pl<sg[lc].size() || pr<sg[rc].size()){
        if (pl>=sg[lc].size()) sg[i].emplace_back(sg[rc][pr++]);
        else if (pr>=sg[rc].size() || sg[rc][pr]>sg[lc][pl]) sg[i].emplace_back(sg[lc][pl++]);
        else sg[i].emplace_back(sg[rc][pr++]);
        while (pl<sg[lc].size() && !sg[i].empty() && sg[lc][pl]==sg[i].back()) pl++;
        while (pr<sg[rc].size() && !sg[i].empty() && sg[rc][pr]==sg[i].back()) pr++;
    }
    return;
}

ll qu (int tl,int tr,int mx,int l=1,int r=n,int i=0){
    if (tl>r || tr<l) return 0;
    if (tl>=l && tr<=r){
        
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        pos[ar[i]].emplace_back(i);
    }
    vector<tuple<ll,ll,ll,ll>> ask;
    for (int i=1;i<=m;i++){
        int bf=0;
        for (auto e:pos[i]){
            ask.emplace_back(e,bf,i-1,ask.size());
            bf=e;
        }
    }
    vector<ll> ans(ask.size());
    sort(ask.begin(),ask.end());
    ll br=0;
    for (auto [r,l,mx,idx]:ask){
        if (r!=br){
            
        }
        ll nv;
        ans[idx]=nv;
    }
    int np=0;
    for (int i=1;i<=m;i++){
        for (auto e:pos[i]){
            int nv=ans[np++];
        }
    }
}