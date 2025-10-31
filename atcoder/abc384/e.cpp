#include <bits/stdc++.h>
using namespace std;

using lll=__int128_t;
using ll=long long;
using db=double;
using pll=pair<ll,ll>;
using tll=tuple<ll,ll,ll>;
const ll N=505;
ll a[N][N],d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool vis[N][N];
priority_queue<tll,vector<tll>,greater<tll>> pq;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll r,c,x,sr,sc,sum;
    cin >> r >> c >> x >> sr >> sc;
    for (int i=1;i<=r;i++) for (int j=1;j<=c;j++) cin >> a[i][j];
    sum=a[sr][sc];
    vis[sr][sc]=1;
    for (int i=0;i<4;i++){
        int xr=sr+d[i][0],xc=sc+d[i][1];
        if (!xr || !xc || xr>r || xc>c || vis[xr][xc]) continue;
            vis[xr][xc]=1;
            pq.emplace(a[xr][xc],xr,xc);
    }
    while (!pq.empty()){
        auto [nv,nr,nc]=pq.top(); pq.pop();
        if (log10(x)+log10(a[nr][nc]) >= 18 || a[nr][nc]*x>=sum) continue;
        // cout << nr  << ' ' << nc << " : " << nv << ' ' << sum << '\n';
        sum+=nv;
        for (int i=0;i<4;i++){
            int xr=nr+d[i][0],xc=nc+d[i][1];
            if (!xr || !xc || xr>r || xc>c || vis[xr][xc]) continue;
            vis[xr][xc]=1;
            pq.emplace(a[xr][xc],xr,xc);
        }
    }
    cout << sum;
}