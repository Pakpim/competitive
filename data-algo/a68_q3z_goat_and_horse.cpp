#include <bits/stdc++.h>
using namespace std;

const int N=3505;
int dist[N][N], d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char c[N][N];
int n,m, sr,sc, tr, tc;
bool vis[N][N];

using ti = tuple<int,int,int>;
queue<ti> pq;

void add(int nd, int nr, int nc){
  if (dist[nr][nc]<=nd || vis[nr][nc]) return;
  dist[nr][nc]=nd;
  pq.emplace(nd,nr,nc);
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> c[i][j];
            if (c[i][j]=='S') sr=i, sc=j;
            if (c[i][j]=='T') tr=i, tc=j;
        }
    }
    for (int i=0;i<=n;i++) for (int j=0;j<=m;j++) dist[i][j]=1e9, vis[i][j]=0;
    // cout << "hi";
    add(0,sr,sc);
    while (!pq.empty()){
        auto [nd,nr,nc]=pq.front();
        pq.pop();
        if (vis[nr][nc]) continue;
        // cout << " ? " << nd << ' ' << nr << ' ' << nc << ' ' << ns << ' ' << c[nr][nc] << '\n';
        dist[nr][nc]=nd;
        vis[nr][nc]=1;
        if (c[nr][nc]=='T' || (nr==0 && nc==tc) || (nc==0 && nr==tr)){
            cout << nd;
            exit(0);
        }
        if (nr==0){
            for (int i=1;i<=n;i++) if (c[i][nc]!='X'){
                if (c[i][nc]=='T'){
                    cout << nd;
                    exit(0);
                }
                if (c[i][nc]=='#') add(nd+1,i,0);
                for (int j=2;j<4;j++){
                    int xr=i+d[j][0], xc=nc+d[j][1];
                    if (!xr || !xc || xr>n || xc>m || c[xr][xc]=='X') continue;
                    if (c[xr][xc]=='#') add(nd+1,xr,0);
                    if (c[xr][xc]=='#') add(nd+1,0,xc);
                    add(nd+1,xr,xc);
                }
            }
            continue;
        }
        if (nc==0){
            for (int i=1;i<=m;i++) if (c[nr][i]!='X'){
                if (c[nr][i]=='T'){
                    cout << nd;
                    exit(0);
                }
                if (c[nr][i]=='#') add(nd+1,0,i);
                for (int j=0;j<2;j++){
                    int xr=nr+d[j][0], xc=i+d[j][1];
                    if (!xr || !xc || xr>n || xc>m || c[xr][xc]=='X') continue;
                    if (c[xr][xc]=='#') add(nd+1,xr,0);
                    if (c[xr][xc]=='#') add(nd+1,0,xc);
                    add(nd+1,xr,xc);
                }
            }
            continue;
        }
        for (int i=0;i<4;i++){
            int xr=nr+d[i][0], xc=nc+d[i][1];
            if (!xr || !xc || xr>n || xc>m || c[xr][xc]=='X') continue;
            if (c[xr][xc]=='#') add(nd+1,xr,0);
            if (c[xr][xc]=='#') add(nd+1,0,xc);
            add(nd+1,xr,xc);
        }
    }
}