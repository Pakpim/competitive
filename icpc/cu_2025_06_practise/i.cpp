#include <bits/stdc++.h>
#define lc i*2+1
#define rc i*2+2
#define mid (l+r)/2
using namespace std;

using ll=long long;
const int N=5e5+5;
vector<int> g[N];
int n,q,t,sg[N*4][2],lz[N*4][2],bg[N],ed[N];

void dfs (int nn,int np){
    t++;
    bg[nn]=t;
    for (auto e:g[nn]) if (e!=np){
        dfs(e,nn);
    }
    ed[nn]=t;
}

void push (int l,int r,int i){
    sg[i][0]=max(sg[i][0],lz[i][0]);
    sg[i][1]=max(sg[i][1],lz[i][1]);
    if (l==r) return;
    lz[lc][0]=max(lz[lc][0],lz[i][0]);
    lz[lc][1]=max(lz[lc][1],lz[i][1]);
    lz[rc][0]=max(lz[rc][0],lz[i][0]);
    lz[rc][1]=max(lz[rc][1],lz[i][1]);
}

void up (int tl,int tr,int v,int l=1,int r=n,int i=0){
    push(l,r,i);
    if (l>tr || r<tl) return;
    if (l>=tl && r<=tr){
        lz[i][v]=max(lz[i][v],t);
        push(l,r,i);
        return;
    }
    up(tl,tr,v,l,mid,lc);
    up(tl,tr,v,mid+1,r,rc);
    sg[i][0]=max(sg[lc][0],sg[rc][0]);
    sg[i][1]=max(sg[lc][1],sg[rc][1]);
}

pair<int,int> qu (int tl,int tr,int l=1,int r=n,int i=0){
    push(l,r,i);
    if (l>tr || r<tl) return {0,0};
    if (l>=tl && r<=tr) return {sg[i][0],sg[i][1]};
    auto [l0,l1]=qu(tl,tr,l,mid,lc);
    auto [r0,r1]=qu(tl,tr,mid+1,r,rc);
    return {max(l0,r0),max(l1,r1)};
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1,0);
    cin >> q;
    t=0;
    while (q--){
        int o,tg;
        t++;
        cin >> o >> tg;
        if (o==1){
            up(bg[tg],ed[tg],1);
        }
        if (o==2){
            up(bg[tg],bg[tg],0);
        }
        if (o==3){
            auto [e,_]=qu(bg[tg],ed[tg]);
            auto [__,f]=qu(bg[tg],bg[tg]);
            if (e>=f) cout << "0\n";
            else cout << "1\n";
        }
        // cout << " => " << t << " : ";
        // for (tg=1;tg<=n;tg++){
        //     auto [e,_]=qu(bg[tg],ed[tg]);
        //     auto [__,f]=qu(bg[tg],bg[tg]);
        //     if (e>f) cout << "0 ";
        //     else cout << "1 ";
        //     // cout << f << ' ';
        // }
        // cout <<'\n';
    }
}
