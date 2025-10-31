#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=3005;
int dp[N][N];
pair<int,int> par[N][N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    string a,b;
    cin >> a >> b;
    for (int i=1;i<=a.size();i++){
        for (int j=1;j<=b.size();j++){
            dp[i][j]=dp[i][j-1];
            par[i][j]={i,j-1};
            if (dp[i-1][j]> dp[i][j]){
                dp[i][j]=dp[i-1][j];
                par[i][j]={i-1,j};
            }
            if (a[i-1]==b[j-1] && dp[i-1][j-1] + 1>dp[i][j]){
                dp[i][j]=dp[i-1][j-1]+1;
                par[i][j]={i-1,j-1};
            }
        }
    }
    stack<char> st;
    int nr = a.size(), nc = b.size();
    while (nr>0 || nc>0){
        auto [xr,xc] = par[nr][nc];
        if (xr == nr-1 && xc == nc-1) st.emplace(a[nr-1]);
        nr=xr;
        nc=xc;
    }
    while (!st.empty()){
        cout << st.top();
        st.pop();
    }
}