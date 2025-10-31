#include <bits/stdc++.h>
using namespace std;

const int N=100005;
priority_queue<int,vector<int>,greater<int>> pq;
vector <int> g[N];
int dp[N];

void dfs(int nn){
    for (auto e:g[nn]) dfs(e);
    for (auto e:g[nn]) pq.emplace(dp[e]);
    while (pq.size()>2){
        pq.pop();
        int v=pq.top(); 
        pq.pop();
        pq.emplace(v+1);
    }
    if (pq.size()>1) pq.pop();
    if (!pq.empty()) dp[nn]=pq.top()+1,pq.pop();
    // cout << " => " << nn << ' ' << dp[nn] << '\n';
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=2;i<=n;i++){
        int p;
        cin >> p;
        g[p].emplace_back(i);
    } 
    dfs(1);
    cout << dp[1];
}