#include<bits/stdc++.h>
using namespace std;

using ll=long long; 

ll dist[1005][1005], d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool f[1005][1005];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m,k,g;
    cin >> n >> m >> k >> g;
    for(ll i=1;i<=n;i++) for(ll j=1;j<=n;j++) dist[i][j]=1e9;
    queue<tuple<ll,ll,ll>> q;
    vector<tuple<ll,ll,ll>> ask;
    while(m--){
        ll x,y;
        cin >> x >> y;
        q.emplace(x,y,0);
    }
    while(k--){
        ll x,y,c;
        cin >> x >> y >> c;
        ask.emplace_back(x,y,c);
    }
    while(g--){
        ll x,y;
        cin >> x >> y;
        f[x][y]=1;
    }
    while(!q.empty()){
        auto [nx,ny,nd]=q.front(); q.pop();
        if (f[nx][ny]) continue;
        if (dist[nx][ny]<=nd) continue;
        dist[nx][ny]=nd;
        for (ll i=0;i<4;i++){
            ll xx=nx+d[i][0], xy=ny+d[i][1];
            if (!xx || !xy || xx>n || xy>n) continue;
            q.emplace(xx,xy,nd+1);
        }
    }
    ll cnt=0;
    for (auto [x,y,c]:ask) cnt+=dist[x][y]*c;
    cout << cnt;
}