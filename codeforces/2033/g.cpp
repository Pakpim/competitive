#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
vector<int> g[N],h2[N];
vector<tuple<int,int>> qu[N];
int ans[N],h[N],dp[N],sg[N*4];
deque<vector<int>> dq;
int n,q;

void dfs1 (int nn,int np){
    for (auto e:g[nn]) {
        if (e!=np) {
            dfs1(e,nn);
            h[nn]=max(h[nn],h[e]);
        }
    }
    h[nn]++;
    int nv=-1e9;
    for (auto e:g[nn]){
        if (e!=np){
            h2[nn].emplace_back(nv);
            nv=max(nv,h[e]);
        }
    }
    nv=-1e9;
    int cnt=h2[nn].size()-1;
    for (int i=g[nn].size()-1;i>=0;i--){
        int e=g[nn][i];
        if (e!=np){
            h2[nn][cnt]=max(h2[nn][cnt],nv);
            nv=max(nv,h[e]);
            cnt--;
        }
    }
    // cout << nn << " : ";
    // for (auto e:h2[nn]) cout << e << ' ';
    // cout << '\n';
}

void up (int idx,int val,int l=0,int r=n-1,int i=0){
    if (l>r) return;
    if (l==r){
        sg[i]=val;
        return;
    }
    int mid=(l+r)/2;
    if (idx<=mid) up(idx,val,l,mid,i*2+1);
    else up(idx,val,mid+1,r,i*2+2);
    sg[i]=max(sg[i*2+1],sg[i*2+2]);
}

int qur (int idx,int l=0,int r=n-1,int i=0){
    if (l>r) return -1e9;
    if (r<idx) return -1e9;
    if (l>=idx) return sg[i];
    int mid=(l+r)/2;
    return max(qur(idx,l,mid,i*2+1),qur(idx,mid+1,r,i*2+2));
}

void dfs2(int nn,int np,int nd){
    for (auto [nk,ni]:qu[nn]){
        ans[ni]=max(h[nn]-1,min(nk,nd));
        int tg=max(0,nd-nk);
        // cout << " => " << nn << ' ' << nk << ' ' << tg << ' ' << ans[ni] << '\n';
        // for (int i=0;i<=nd;i++){
        //     cout << "\t -> " << i << ' ' << qur(i) << '\n';
        // }
        if (tg<nd) ans[ni]=max(ans[ni],qur(tg)+nd);
    }
    int cnt=0;
    for (auto e:g[nn]) {
        if (e!=np) {
            up(nd,h2[nn][cnt]-nd);
            dfs2(e,nn,nd+1);
            up(nd,-1e9);
            cnt++;
        }
    }
}

void solve (){
    cin >> n;
    for (int i=0;i<=n;i++) up(i,-1e9);
    for (int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    cin >> q;
    for (int i=1;i<=q;i++){
        int v,k;
        cin >> v >> k;
        qu[v].emplace_back(k,i);
    }
    dfs1(1,0);
    dfs2(1,0,0);
    for (int i=1;i<=q;i++) cout << ans[i] << ' ';
    cout << '\n';
    for (int i=1;i<=n;i++) g[i].clear(),h[i]=0,h2[i].clear(),qu[i].clear();
    for (int i=1;i<=q;i++) ans[i]=-1e9;
    for (int i=0;i<=n;i++) up(i,-1e9);
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}