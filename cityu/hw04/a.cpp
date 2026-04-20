#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=150;
ll a[N][N], b[N][N], d[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
bool vis[N][N][305];
queue<tuple<ll,ll,ll>> q;

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll r,c,k;
    cin >> r >> c >> k;
    for (ll i=1;i<=r;i++) for (ll j=1;j<=c;j++) a[i][j]=105, b[i][j]=0;
    while (k--){
        ll nr,nc,na,nb;
        cin >> nr >> nc >> na >> nb;
        a[nr][nc]=na;
        b[nr][nc]=nb;
    }
    q.emplace(1,1,0);
    while (!q.empty()){
        auto [nr,nc,nt]=q.front();
        q.pop();
        if (a[nr][nc]<=nt && b[nr][nc]>=nt) return 1;
        if (vis[nr][nc][nt]) continue;
        vis[nr][nc][nt]=1;
        if (nr==r && nc==c){
            cout << nt;
            return 0;
        }
        for (ll i=0;i<4;i++){
            ll xr=nr+d[i][0], xc=nc+d[i][1], xt=nt+1;
            if (!xr || !xc || xr>r || xc>c || (a[xr][xc]<=xt && b[xr][xc]>=xt)) continue;
            q.emplace(xr,xc,xt);
        }
    }
    return 1;
}