#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using tll = tuple<ll,ll,ll>;
const int N=205;
vector<ll> g[N];
priority_queue<tll,vector<tll>,greater<tll>> pq;
ll dist[N][N],x[N], y[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m,k,r;
    cin >> n >> m >> k >> r;
    for (int i=1;i<=n;i++) cin >> x[i] >> y[i];
    for (int i=1;i<=m;i++) cin >> x[i+n] >> y[i+n];
    for (int i=1;i<=n+m;i++) for (int j=0;j<=k;j++) dist[i][j]=1e18;
    for (int i=1;i<=n+m;i++){
        for (int j=i+1;j<=n+m;j++){
            ll dx=x[i]-x[j], dy=y[i]-y[j];
            // cout << i << ' ' << j << " => " << dx << ' ' << dy << ' '<< dx*dx+dy*dy << ' ' << r*r << '\n';
            if (dx*dx+dy*dy<=r*r){
                g[i].emplace_back(j);
                g[j].emplace_back(i);
            }
        }
    }
    // for (int i=1;i<=n+m;i++){
    //     cout << i << " : ";
    //     for (auto e:g[i]) cout << e << ' ';
    //     cout << '\n';
    // }
    pq.emplace(0,1,0);
    while (!pq.empty()){
        auto [nd,nn,nk]=pq.top();
        pq.pop();
        if (dist[nn][nk]<=nd) continue;
        // cout << " ? " << nn << ' ' << nk << ' ' << nd << '\n';
        dist[nn][nk]=nd;
        if (nn==2){
            cout << nd-1;
            return 0;
        }
        for (auto e:g[nn]){
            if (e>n){
                if (nk<k) pq.emplace(nd+1,e,nk+1);
            }
            else pq.emplace(nd+1,e,nk);
        }
    }
}