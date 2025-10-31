#include <bits/stdc++.h>
using namespace std;

const int N=10005,K=15;
vector<pair<int,int>> g[N];
int dp1[N],dp2[N],a[K],b[K],c[K];
bool used[N];

void dfs (int nn,int np){
    for (auto [xn,xw]:g[nn]){
        if (xn!=np) {
            dfs(xn,nn);
            dp1[nn]+=dp2[xn];
        }
    }
    dp2[nn]=dp1[nn];
    if (!used[nn]){
        for (auto [xn,xw]:g[nn]){
            if (xn!=np && !used[xn]) dp2[nn]=max(dp2[nn],dp1[xn]+dp1[nn]-dp2[xn]+xw);
        }
    }
    cout << " => " << nn << ' ' << np << ' ' << dp1[nn] << ' ' << dp2[nn] << '\n';
    return;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k,ans=0;
    cin >> n >> k;
    for (int i=1;i<n;i++){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    for (int i=0;i<k;i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i=0;i<1<<k;i++){
        for (int j=1;j<=n;j++) used[j]=dp1[j]=dp2[j]=0;
        int nv=0;
        for (int j=0;j<k;j++){
            if (i&1<<j && !used[a[j]] && !used[b[j]]) {
                nv+=c[j];
                used[a[j]]=1;
                used[b[j]]=1;
            }
        }
        cout << bitset<10>(i) << '\n';
        dfs(1,0);
        ans=max(ans,dp2[1]+nv);
    }
    cout << ans;
}

/*
0000000000
 => 2 1 0 0
 => 4 3 0 0
 => 6 5 0 0
 => 5 3 0 200
 => 3 1 200 400
 => 1 0 400 500
0000000001
 => 2 1 0 0
 => 4 3 0 0
 => 6 5 0 0
 => 5 3 0 200
 => 3 1 200 200
 => 1 0 200 210
0000000010
 => 2 1 0 0
 => 4 3 0 0
 => 6 5 0 0
 => 5 3 0 0
 => 3 1 0 200
 => 1 0 200 200
0000000011
 => 2 1 0 0
 => 4 3 0 0
 => 6 5 0 0
 => 5 3 0 0
 => 3 1 0 50
 => 1 0 50 50
750%
*/