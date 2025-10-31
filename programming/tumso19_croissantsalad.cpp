#include <bits/stdc++.h>
using namespace std;

const int N=605;
int g[N][N],n;
bool vis[N],used[N],f;

void dfs(int nn,int np){
    vis[nn]=1;
    if (nn&1 && !used[nn]){
        used[nn]=1;
        f=1;
    }
    for (int i=2;i<=n*2+1;i++){
        if (f) break;
        if (vis[i] || !g[nn][i]) continue;
        dfs(i,nn);
    }
    if (f && np){
        g[np][nn]--;
        g[nn][np]++;
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int m,cnt=0;
    cin >> n >> m;
    for (int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        g[u*2][v*2+1]++;
    }
    for (int i=1;i<=n;i++){
        f=0;
        for (int j=2;j<=n*2+1;j++) vis[j]=0;
        dfs(i*2,0);
        cnt+=f;
    }
    cout << m-cnt+n-cnt;
}

/*
6 10
1 2
1 3
2 2
3 1
3 3
4 1
4 4
5 3
5 6
6 4
*/