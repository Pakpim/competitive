#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=4e5+5;

map<tuple<int,int,int>,int> mp;
vector<tuple<int,int,int,int,int>> ev;
vector<tuple<int,int,int>> sg[N*4];
int q,n,ans[N],par[N][2],h[N][2],cnt[2];

int root(int nn,int nc){
    if (!par[nn][nc]) return nn;
    return root(par[nn][nc],nc);
}

void up (int tl,int tr,tuple<int,int,int> nt,int l=1,int r=q,int i=0){
    if (tl>r || tr<l) return;
    if (tl<=l && tr>=r){
        sg[i].emplace_back(nt);
        return;
    }
    int mid=(l+r)/2;
    up(tl,tr,nt,l,mid,i*2+1);
    up(tl,tr,nt,mid+1,r,i*2+2);
    return;
}

void rec(int l=1,int r=q,int i=0){
    if (l>r) return;
    deque<tuple<int,int,int,int>> dq;
    for (auto [c,u,v]:sg[i]){
        for (int k=c;k<2;k++){
            u=root(u,k); v=root(v,k);
            if (u==v) continue;
            if (h[u][k]>h[v][k]) swap(u,v);
            dq.emplace_back(u,v,k,h[v][k]);
            par[u][k]=v;
            h[v][k]=max(h[v][k],h[u][k]+1);
            cnt[k]++;
        }
    }
    // cout << l << ' ' << r << " => " << cnt[0] << ' ' << cnt[1] << '\n';
    if (l!=r){
        int mid=(l+r)/2;
        rec(l,mid,i*2+1);
        rec(mid+1,r,i*2+2);
    }
    else{
        ans[l]=cnt[1]-cnt[0];
    }
    while (!dq.empty()){
        auto [u,v,c,bh]=dq.back();
        dq.pop_back();
        par[u][c]=0;
        h[v][c]=bh;
        cnt[c]--;
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i=1;i<=q;i++){
        char c;
        int c2,u,v;
        cin >> c >> u >> v;
        c2=c-'A';
        if (u>v) swap(u,v);
        if (mp.count({c2,u,v})){
            up(mp[{c2,u,v}],i-1,{c2,u,v});
            mp.erase({c2,u,v});
        }
        else mp[{c2,u,v}]=i;
    }
    for (auto [nt,nl]:mp){
        up(nl,q,nt);
    }
    rec(1,q);
    for (int i=1;i<=q;i++) cout << ans[i] << '\n';
}