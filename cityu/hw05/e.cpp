#include <bits/stdc++.h>
using namespace std;

const int N=404;
vector<int> g[2][N*3];
int lv[N*3],cur[N*3],cnt,n,m, a[N], b[N];
vector<int> fr,to,cap;

bool bfs(int t, int st, int tg){
    for (int i=0;i<=N*2+n;i++) lv[i]=0;
    queue<tuple<int,int>> q;
    q.emplace(st,1);
    while (!q.empty()){
        auto [nn,nd]=q.front();
        q.pop();
        if (lv[nn]) continue;
        lv[nn]=nd;
        for (auto e:g[t][nn]) {
            if (!cap[e]) continue;
            q.emplace(to[e], nd+1);
        }
    }
    return lv[tg];
}

int dfs(int t,int nn,int tg,int np){
    if (!np) return 0;
    if (nn==tg) return np;
    while (cur[nn]<g[t][nn].size()){
        int e=g[t][nn][cur[nn]];
        cur[nn]++;
        if (cap[e]<1 || lv[to[e]]!=lv[nn]+1) continue;
        int xp=dfs(t,to[e],tg, min(np, cap[e]));
        if (!xp) continue;
        // if (t==1) cout << " ? " << nn << ' ' << to[e] << ' ' << xp << '\n';
        cap[e]-=xp;
        cap[e^1]+=xp;
        return xp;
    }
    return 0;
}
void add (int u,int v,int t){
    fr.emplace_back(u); to.emplace_back(v), cap.emplace_back(1);
    g[t][u].emplace_back(cnt++);
    fr.emplace_back(v); to.emplace_back(u), cap.emplace_back(0);
    g[t][v].emplace_back(cnt++);
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i] >> b[i];
        for (int j=a[i]+n;j<=b[i]+n;j++) {
            add(j,i,0);
            if (i<=m) add(i,j,1);
            else add(j+N,i,1);
        }
    }
    for (int i=n+1;i<n+N;i++) if (!g[0][i].empty()) add(0,i,0);
    for (int i=1;i<=n;i++) if (!g[0][i].empty()) add(i,N+n,0);
    for (int i=1;i<=m;i++) if (!g[1][i].empty()) add(0,i,1);
    for (int i=n+1;i<n+N;i++) add(i,i+N,1);
    for (int i=m+1;i<=n;i++) if (!g[1][i].empty()) add(i,N*2+n,1);
    int tg=n+N;
    for (int t=0;t<2;t++){
        int sum=0;
        int tmp=0;
        while (bfs(t,0,tg)){
            tmp++;
            for (int i=0;i<=tg;i++) cur[i]=0;
            while (1){
                int nf=dfs(t,0,tg,1e9);
                if (!nf) break;
                sum+=nf;
            }
        }
        cout << sum << '\n';
        tg=N*2+n;
    }
}

/*
4 2
1 1
1 1
1 1
1 1
*/