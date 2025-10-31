#include <bits/stdc++.h>
using namespace std;

const int N=4e5+5;
int par[N],cnt[N],sz[N];
bool vis[N];

int root (int nn){
    if (!par[nn]) return nn;
    return par[nn]=root(par[nn]);
}

void uni (int a,int b){
    a=root(a); b=root(b);
    if (a==b) return;
    if (sz[a]<sz[b]) swap(a,b);
    par[b]=a;
    sz[a]+=sz[b];
    cnt[a]+=cnt[b];
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,m;
        cin >> n >> m;
        for (int i=1;i<=2*n;i++) par[i]=0,cnt[i]=0,vis[i]=0,sz[i]=1;
        for (int i=1;i<=n;i++) cnt[i]=1;
        while (m--){
            int u,v;
            string s;
            cin >> u >> v >> s;
            if (s=="imposter"){
                uni(u,v+n);
                uni(u+n,v);
            }
            else{
                uni(u,v);
                uni(u+n,v+n);
            }
        }
        bool ok=1;
        int ans=0;
        for (int i=1;i<=n;i++){
            if (root(i)==root(i+n)) ok=0;
            // cout << i << " => " << par[i] << ' '  << vis[i] << ' ' << cnt[i] << '\n';
            if (!par[i]) {
                ans+=max(cnt[i],sz[i]-cnt[i]);
                // vis[root(i+n)]=1;
            }
        }
        if (ok) cout << ans << '\n';
        else cout << "-1\n";
    }
}