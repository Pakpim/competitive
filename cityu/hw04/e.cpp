#include <bits/stdc++.h>
using namespace std;

// using ll=long long;
using tint=tuple<int,int,int>;
const int N=1e5+5,inf=1e9;
string s[N], t;
map<char,int> mp;
vector<tuple<int,int,int>> g1[30],g[30];
priority_queue<tint,vector<tint>,greater<tint>> pq;
int dist[30][30][1<<11], hs[N];
bool vis[30][1<<11];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n >> t;
    for (int i=1;i<=n;i++) cin >> s[i];
    int cnt=0;
    for (auto e:t) mp[e]=cnt++;
    int tg=(1<<(int(t.size())))-1;
    for (int i=1;i<=n;i++){
        for (auto e:s[i]) if (mp.count(e)) hs[i]|=1<<mp[e];
        g1[s[i][s[i].size()-1]-'a'].emplace_back(s[i].size()-1, s[i][0]-'a', hs[i]);
    }
    for (int i=0;i<26;i++){
        sort(g1[i].begin(), g1[i].end());
        for (int j=0;j<26;j++) for (int k=0;k<=tg;k++) vis[j][k]=0;
        for (auto [nw,nx,nv]:g1[i]){
            if (vis[nx][nv]) continue;
            vis[nx][nv] = 1;
            g[i].emplace_back(nx,nv,nw);
        }
    }
    for (int i=0;i<26;i++) for(int j=0;j<26;j++) for (int k=0;k<=tg;k++) dist[i][j][k]=inf;
    for (int i=0;i<26;i++){
        while (!pq.empty()) pq.pop();
        for (int j=0;j<26;j++) for (int k=0;k<=tg;k++) vis[j][k]=0;
        pq.emplace(0,i,0);
        dist[i][i][0]=0;
        while (!pq.empty()){
            auto [nd,nn,nv]=pq.top();
            pq.pop();
            if (nn<0 || nn>26) exit(0);
            if (nv<0 || nv>tg) exit(0);
            if (vis[nn][nv]) continue;
            vis[nn][nv]=1;
            dist[i][nn][nv]=nd;
            for (auto [xn,xv,xw]:g[nn]){
                if (dist[i][xn][nv|xv]<=nd+xw) continue;
                pq.emplace(nd+xw,xn,nv|xv);
                dist[i][xn][nv|xv]=nd+xw;
            }
            if (t.size()>5 && pq.size()>10000000) exit(0);
        }
        for (int j=0;j<26;j++){
            for (int k=tg;k>0;k--){
                if (dist[i][j][k]==inf) continue;
                for (int x=1;x<=k;x<<=1){
                    if (k&x) dist[i][j][k-x]=min(dist[i][j][k-x], dist[i][j][k]);
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        int nf=s[i][0]-'a', nb=s[i][s[i].size()-1]-'a', nv=(~hs[i])&tg;
        int ans=dist[nf][nb][nv];
        if (ans==inf) cout << "-1\n";
        else cout << ans+s[i].size()-1 << '\n';
    }
}

/*
6 aulsghkiny
aqua
glass
hug
shiny
sparkling
youth

6 au
aqua
glass
hug
shiny
sparkling
youth
*/