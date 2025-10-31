#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1005;
pair<int,int> par[N][N];
bool ok[N][N];
int sz[N][N],n,m;

pair<int,int> root (pair<int,int> np){
    auto [nr,nc]=np;    
    if (!par[nr][nc].first && !par[nr][nc].second) return {nr,nc};
    return root(par[nr][nc]);
}

void uni (pair<int,int> up,pair<int,int> vp){
    up=root(up);
    auto [ur,uc]=up;
    auto [vr,vc]=vp;
    if (!vr || !vc || vr>n || vc>m){
        ok[ur][uc]=0;
        return;
    }
    vp=root(vp);
    if (up==vp) return;
    vr=vp.first; vc=vp.second;
    if (sz[ur][uc]>sz[vr][vc]){
        swap(ur,vr);
        swap(uc,vc);
    }
    sz[vr][vc]+=sz[ur][uc];
    if (!ok[ur][uc]) ok[vr][vc]=0;
    par[ur][uc]={vr,vc};
    return;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        cin >> n >> m;
        vector<string> v(n);
        for (auto &e:v) cin >> e;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                ok[i][j]=1;
                sz[i][j]=1;
                par[i][j]={0,0};
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                char c=v[i-1][j-1];
                if (c=='U'){
                    uni({i,j},{i-1,j});
                }
                if (c=='D'){
                    uni({i,j},{i+1,j});
                }
                if (c=='L'){
                    uni({i,j},{i,j-1});
                }
                if (c=='R'){
                    uni({i,j},{i,j+1});
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                char c=v[i-1][j-1];
                if (c!='?') continue;
                int di[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
                bool f=0;
                for (int k=0;k<4;k++){
                    auto [ri,rj]=root({i+di[k][0],j+di[k][1]});
                    if (ok[ri][rj]){
                        uni({i,j},{ri,rj});
                        f=1;
                        break;
                    }
                }
                if (!f) ok[i][j]=0;
            }
        }
        int ans=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                auto [ri,rj]=root({i,j});
                // if (root({i,j})==make_pair(i,j) && ok[i][j]){
                //     ans+=sz[i][j];
                // }
                if (ok[ri][rj]) ans++;
                // cout << ri << ',' << rj << '=' << ok[ri][rj] << ' ';
            }
            // cout << '\n';
        }
        cout << ans << '\n';
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                ok[i][j]=0;
                sz[i][j]=0;
                par[i][j]={0,0};
            }
        }
    }
}

/*
1
4 5
???UU
???UU
?????
DD???
*/