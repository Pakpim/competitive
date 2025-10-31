#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=1e5+5,M=1e9+7;
ll a[N];
vector<int> g[N], rg[N];
int f[N],f2[N];

stack<int> st;
void dfs(int nn){
    if (f[nn]) return;
    f[nn]=1;
    for (auto e:g[nn]) dfs(e);
    st.emplace(nn);
}

vector<int> cc;
void dfs2(int nn){
    if (f2[nn]) return;
    f2[nn]=1;
    cc.emplace_back(a[nn]);
    for (auto e:rg[nn]){
        dfs2(e);
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    ll sum = 0, ans = 1;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    cin >> m;
    while (m--){
        int u,v;
        cin >> u >> v;
        g[u].emplace_back(v);
        rg[v].emplace_back(u);
    }
    for (int i=1;i<=n;i++){
        if (f[i]) continue;
        dfs(i);
    }
    while (!st.empty()){
        auto nn = st.top();
        st.pop();
        if (f2[nn]) continue;
        cc.clear();
        dfs2(nn);
        sort(cc.begin(),cc.end());
        int nv = cc[0], cnt = 0;
        for (auto e:cc){
            if (e>nv) break;
            cnt++;
        }
        // cout << " => " << nv << ' ' << cnt << '\n';
        sum += nv;
        ans = (ans*cnt)%M;
    }
    cout << sum << ' ' << ans;
}