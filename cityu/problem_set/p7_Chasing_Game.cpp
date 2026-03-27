#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
vector<int> g[N];
int dist[N], t[N], lg[N*2] ,par[N][20], _t;
pair<int,int> mn[N*2][20];

void dfs(int nn,int np,int nd){
    dist[nn]=nd;
    mn[t[nn]][0]={nd,nn};
    par[nn][0]=np;
    for (auto e:g[nn]) if (e!=np) {
        mn[_t][0]={nd,nn};
        t[nn]=min(t[nn],_t++);
        mn[_t][0]={nd+1,e};
        t[e]=min(t[e],_t++);
        dfs(e,nn,nd+1);
    }
}

int lca (int u,int v){
    if (t[u]>t[v]) swap(u,v);
    int nl=lg[t[v]-t[u]], nr=t[v]-(1<<nl)+1;
    // cout << " ? " << u << ' ' << v << ' ' << nl << ' ' << t[v]-t[u] << ' ' << t[u] << ' ' << nr << '\n';
    auto [nv,nn]=min(mn[t[u]][nl], mn[nr][nl]);
    return nn;
}

int d(int u,int v){
    return dist[u]+dist[v]-(dist[lca(u,v)]<<1);
}

int jump(int u,int k){
    for (int i=0;i<=lg[k];i++){
        if (k>>i&1) u=par[u][i];
    }
    return u;
}

signed main (){
    // ios::sync_with_stdio(0); cin.tie(0);
    int n,q;
    // cin >> n >> q;
    scanf("%d %d",&n,&q);
    for (int i=1;i<n;i++){
        int u,v;
        // cin >> u >> v;
        scanf("%d %d",&u,&v);
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for (int i=1, j=0;i<=n*4;i++){
        if (i>=(1<<j)) j++;
        lg[i]=j-1;
    }
    for (int i=1;i<=n;i++) t[i]=1e9;
    t[1]=_t++;
    dfs(1,1,0);
    for (int i=1;i<=19;i++){
        for (int l=0,r=l+(1<<(i-1));r<_t;l++,r++){
            mn[l][i]=min(mn[l][i-1],mn[r][i-1]);
        }
        for (int j=1;j<=n;j++) par[j][i]=par[par[j][i-1]][i-1];
    }
    int tmp=0;
    while (q--){
        tmp++;
        int s,t,a;
        // cin >> s >> t >> a;
        scanf("%d %d %d",&s,&t,&a);
        int l1=lca(s,t), l2=lca(s,a), l3=lca(t,a), p;
        if (l2==l1) p=l3;
        else if (l3==l1) p=l2;
        else p=l1;
        int d1=d(s,p), d2=d(a,p), d3=dist[a]+dist[t]-(dist[l3]<<1);
        if (d1>=d2) {
            int nd=d2+((d1-d2)>>1)+((d1-d2)&1), np, dsl1=dist[s]-dist[l1];
            if (dsl1>=nd){
                np=jump(s,nd);
            }
            else{
                np=jump(t,dist[t]-dist[l1]-(nd-dsl1));
            }
            // cout << nd << ' ' << np << '\n';
            printf("%d %d\n",nd,np);
        }
        // else cout << d3 << ' ' << t << '\n';
        else printf("%d %d\n",d3,t);
        // if (tmp==1000) break;
    }
}

/*
5 3 
1 2 
1 3 
3 4 
3 5 
4 1 2 
3 5 1 
5 2 4
*/