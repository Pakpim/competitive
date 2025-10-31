#include<bits/stdc++.h>
using namespace std;

using db=double;
const int N=100005;
db x[N],y[N],z[N],sd[N];
vector<pair<int,db>> g[N];
priority_queue<tuple<db,int>,vector<tuple<db,int>>,greater<tuple<db,int>>> pq;
bool vis[N];

db dist (int i,int j){
    return sqrt(sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j])));
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    for (int i=1;i<=n;i++){
        cin >> x[i] >> y[i] >> z[i];
    }
    while (m--){
        int u,v;
        cin >> u >> v;
        g[u].emplace_back(v,dist(u,v));
        g[v].emplace_back(u,dist(u,v));
    }
    for (int i=1;i<=n;i++) sd[i]=1e15;
    pq.emplace(0,1);
    while (!pq.empty()){
        auto [nd,nn]=pq.top();
        pq.pop();
        if (vis[nn]) continue;
        vis[nn]=1;
        for (auto [xn,xd]:g[nn]){
            if (sd[xn]>nd+xd){
                sd[xn]=nd+xd;
                pq.emplace(sd[xn],xn);
            }
        }
    }
    while (q--){
        int c;
        db t,k;
        cin >> c >> t;
        k=t/sd[c];
        if (k<2) printf("impossible\n");
        else printf("%.10f\n",sd[c]*(k-sqrt(k*k-4)));
    }
}