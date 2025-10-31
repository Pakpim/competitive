#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=200005;
vector <int> g[N];
queue<tuple<ll,ll,ll>> q;
bool vis[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll n,b,mx[]={0,0};
        cin >> n;
        for (int i=1;i<n;i++){
            int u,v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        cin >> b >> b;
        q.emplace(1,0,0);
        q.emplace(b,0,1);
        while (!q.empty()){
            auto [nn,nd,np]=q.front();
            q.pop();
            mx[np]=max(mx[np],nd);
            for (auto e:g[nn]){
                if (!vis[e]){
                    vis[e]=1;
                    q.emplace(e,nd+1,np);
                }
            }
        }
        if (mx[0]>mx[1]) cout << "Alice\n";
        else cout << "Bob\n";
        for (int i=1;i<=n;i++) vis[i]=0,g[i].clear();
    }
}