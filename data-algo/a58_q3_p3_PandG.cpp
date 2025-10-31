#include <bits/stdc++.h>
using namespace std;

int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int r,c,n,q,sr,sc;
        cin >> r >> c >> n >> q >> sr >> sc;
        vector<pair<int,int>> g[q+5];
        string s[r+5];
        vector<vector<bool>> vis(r+5,vector<bool>(c+5,0));
        for (int i=0;i<n;i++){
            int nt,nr,nc;
            cin >> nt >> nr >> nc;
            g[nt].emplace_back(nr,nc);
        }
        for (int i=0;i<r;i++) cin >> s[i];
        vector<pair<int,int>> b[2];
        for (int i=0;i<=q;i++){
            int ni=i&1, bi=ni^1;
            b[ni].clear();
            for (auto [nr,nc]:g[i]){
                if (vis[nr][nc] || s[nr][nc]=='#') continue;
                vis[nr][nc]=1;
                b[ni].emplace_back(nr,nc);
            }
            for (auto [br,bc]:b[bi]){
                for (int j=0;j<4;j++){
                    int nr=br+d[j][0], nc=bc+d[j][1];
                    if (nr<0 || nc<0 || nr>=r || nc>=c || vis[nr][nc] || s[nr][nc]=='#') continue;
                    vis[nr][nc]=1;
                    b[ni].emplace_back(nr,nc);
                }
            }
        }
        queue<tuple<int,int,int>> m;
        bool ans=0;
        vector<vector<bool>> vis2(r+5,vector<bool>(c+5,0));
        m.emplace(sr,sc,0);
        while (!m.empty()){
            auto [nr,nc,nt]=m.front();
            m.pop();
            if (vis2[nr][nc]) continue;
            vis2[nr][nc]=1;
            if (!vis[nr][nc]){
                ans=1;
            }
            if (nt==q) continue;
            for (int i=0;i<4;i++){
                int xr=nr+d[i][0],xc=nc+d[i][1];
                if (xr>=0 && xc>=0 && xr<r && xc<c && !vis2[xr][xc] && s[xr][xc]!='#') m.emplace(xr,xc,nt+1);
            }
        }
        if (ans) cout << "YES\n";
        else cout << "NO\n";
        // for (int i=0;i<r;i++){
        //     for (int j=0;j<c;j++) cout << vis2[i][j] << ' ';
        //     cout << '\n';
        // }
    }
}