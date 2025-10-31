#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using pi=pair<int,int>;
int a[55][55],dg[55][55];
vector<pi> g[55][55];
queue <pi> q;
bool vis[55][55],dt[105][105];
string ans[105];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=0;i<2*n-1;i++){
        for (int j=0;j<2*m-1;j++){
            char c;
            cin >> c;
            if (c!='.') a[i/2+1][j/2+1]=c-'0';
            ans[i]+=c;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            for (int k=0;k<2;k++){
                int xi=i-(k&1), xj=j-((k+1)&1);
                if (((a[i][j]==2 || a[i][j]==4) && (a[xi][xj]==2 || a[xi][xj]==4)) or (a[i][j]==7 && a[xi][xj]==7)){
                    g[i][j].emplace_back(xi,xj);
                    g[xi][xj].emplace_back(i,j);
                }
            }
        }
    }
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) dg[i][j]=g[i][j].size();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (vis[i][j]) continue;
            if ((a[i][j]==2 || a[i][j]==4 || a[i][j]==7) && dg[i][j]==0){
                cout << "NO";
                exit(0);
            }
            if (dg[i][j]==1){
                q.emplace(i,j);
                while (!q.empty()){
                    auto [ni,nj]=q.front();
                    q.pop();
                    if (vis[i][j]) continue;
                    vis[i][j]=1;
                    for (auto [ci,cj]:g[ni][nj]){
                        if (!vis[ci][cj]){
                            vis[ci][cj]=1;
                            dt[ni+ci-2][nj+cj-2]=1;
                            for (auto [xi,xj]:g[ci][cj]){
                                if (vis[xi][xj]) continue;
                                dg[xi][xj]--;
                                if (dg[xi][xj]==1) q.emplace(xi,xj);
                                if (dg[xi][xj]==0){
                                    cout << "NO";
                                    exit(0);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (vis[i][j]) continue;
            if ((a[i][j]==2 || a[i][j]==4 || a[i][j]==7) && dg[i][j]==0){
                cout << "NO";
                exit(0);
            }
            if (a[i][j]==2 || a[i][j]==4 || a[i][j]==7){
                q.emplace(i,j);
                while (!q.empty()){
                    auto [ni,nj]=q.front();
                    q.pop();
                    if (vis[i][j]) continue;
                    vis[i][j]=1;
                    for (auto [ci,cj]:g[ni][nj]){
                        if (!vis[ci][cj]){
                            vis[ci][cj]=1;
                            dt[ni+ci-2][nj+cj-2]=1;
                            for (auto [xi,xj]:g[ci][cj]){
                                if (vis[xi][xj]) continue;
                                dg[xi][xj]--;
                                if (dg[xi][xj]==1) q.emplace(xi,xj);
                                if (dg[xi][xj]==0){
                                    cout << "NO";
                                    exit(0);
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
    for (int i=0;i<n*2-1;i++){
        for (int j=0;j<m*2-1;j++){
            if (dt[i][j]) cout << '.';
            else cout << ans[i][j];
        }
        cout << '\n';
    }
}