#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5;

int n;
int a[N];
int root=1;
stack<int> s;
int l[N],r[N],dp[N];
int ans=0;

int dfs(int u){
    if(!u){
        dp[u]=-1;
        return -1;
    }
    int dl=dfs(l[u])+1;
    int dr=dfs(r[u])+1;
    ans=max(ans,dl+dr);
    dp[u]=max({dp[l[u]]+1,dp[r[u]]+1,dl+dr});
    // cout << u << ' ' << a[u] << " => " << dp[u] << '\n';
    return max(dl,dr);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    s.emplace(1);
    for(int i=2;i<=n;i++){
        while(!s.empty()&&a[s.top()]<a[i]){
            l[i]=s.top();
            s.pop();
        }
        if(s.empty())root=i;
        else r[s.top()]=i;
        s.emplace(i);
    }
    dfs(root);
    cout << dp[root];
}