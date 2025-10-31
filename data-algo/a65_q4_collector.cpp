#include <bits/stdc++.h>
using namespace std;

using bs=bitset<1005>;
const int N=85,R=0;
int p[N],qs[N];
bs f[N],qf[N];
vector<pair<double,int>> v[1005],v2;
vector<int> bb[85];
int n,k,ans=0;
int cnt[1005];

void dfs (int sum,int nn){
    if (nn==n){
        ans=min(ans,sum);
        return;
    }
    if (sum>=ans) return;
    if (cnt[nn]) dfs(sum,nn+1);
    else {
        for (auto [db,ni]:v[nn]){
            for (auto e:bb[ni]) cnt[e]++;
            dfs(sum+p[ni],nn+1);
            for (auto e:bb[ni]) cnt[e]--;
        }
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i=0;i<k;i++){
        int b;
        cin >> p[i] >> b;
        ans+=p[i];
        for (int j=0;j<b;j++){
            int x;
            cin >> x;
            if (k>R) bb[i].emplace_back(x-1);
            f[i][x-1]=1;
            v[x-1].emplace_back(double(p[i])/double(b),i);
        }
        v2.emplace_back(double(p[i])/double(b),i);
    }
    for (int i=0;i<n;i++) sort(v[i].begin(),v[i].end());
    sort(v2.begin(),v2.end());
    for (int i=k;i>=0;i--) qs[i]=qs[i+1]+p[v2[i].second],qf[i]=qf[i+1]|f[v2[i].second];
    if (k>R) dfs(0,0);
    else{
        stack<tuple<int,int,bs>> q;
        q.push({0,0,bs(0)});
        while (!q.empty()){
            auto [sum,nn,nb]=q.top(); q.pop();
            if (nb.count()==n){
                ans=min(ans,sum);
                continue;
            }
            if (nn==k) continue;
            if ((qf[nn]|nb).count()<n) continue;
            if (sum>=ans) continue;
            q.push({sum,nn+1,nb});
            q.push({sum+p[v2[nn].second],nn+1,nb|f[v2[nn].second]});
        }
    }
    cout << ans;
}