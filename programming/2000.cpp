#include <bits/stdc++.h>
using namespace std;

const int N=100005;
int g[N][2],dp[N],mn[N],mx[N];

void dfs (int nn){
    if (!nn) return;
    int l=g[nn][0],r=g[nn][1];
    dfs(l);
    dfs(r);
    mx[nn]=max(mx[l],mx[r])+1;
    mn[nn]=min(mn[l],mn[r])+1;
    if ((mn[l]<mx[r] && mn[r]<mx[l]) || 
        (mx[nn]-mn[nn]>1) || dp[l]==-1 || dp[r]==-1){
        dp[nn]=-1;
    }
    else{
        dp[nn]=dp[l]+dp[r];
        if (mn[l]<mx[r]) dp[nn]++;
    }
    // cout << " => " << nn << ' ' << dp[nn] << ' ' << mn[nn] << ' ' << mx[nn] << '\n';
    return;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++){
        int l,r;
        cin >> l >> r;
        if (l!=-1) g[i][0]=l;
        if (r!=-1) g[i][1]=r; 
    }
    dfs(1);
    cout << dp[1];
}