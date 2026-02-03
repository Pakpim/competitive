#include <bits/stdc++.h>
using namespace std;

const int N=7,K=3;

int pos[2]={3,4}, d[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}}, cnt=0, mx;
bool f[N+5][N+5];
char dir[N+5][N+5], c[4]={'V', '^', '<', '>'};
deque<pair<int,int>> dq;

void dfs (int nr, int nc, int tr, int tc, int vis){
    // cout << "? " << vis << " : " << nr << ' ' << nc << '\n';
    if (vis>K && !f[pos[0]][pos[1]]) return;
    mx=max(mx,vis);
    if (vis>=N*N && f[pos[0]][pos[1]]){
        if (nr==tr && nc==tc){
            for (int i=N;i>0;i--){
                for (int j=1;j<=N;j++){
                    cout << dir[i][j];
                }
                cout << '\n';
            }
            cout << '\n';
            for (auto [f,s]:dq) cout << f << ' ' << s << '\n';
            exit(0);
        }
        return;
    }
    if (nr==pos[0] && nc==pos[1]){
        if (vis!=K+1) return;
    }
    for (int i=0;i<4;i++){
        int xr=nr+d[i][0], xc=nc+d[i][1];
        if (xr<1 || xc<1 || xr>N || xc>N || f[xr][xc]) continue;
        f[xr][xc]=1;
        dir[nr][nc]=c[i];
        dq.emplace_back(xr,xc);
        dfs(xr,xc,tr,tc,vis+1);
        dq.pop_back();
        dir[nr][nc]='.';
        f[xr][xc]=0;
    }
}

int main (){
    for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) dir[i][j]='.';
    // dfs(0,5,3,1,0);
    // dfs(0,3,3,1,0);
    dfs(3,0,3,7,0);
    cout << mx << '\n';
    cout << "no\n";
}