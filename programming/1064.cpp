#include <bits/stdc++.h>
using namespace std;

using pi=pair<int,int>;
const int N=70;
string s[N];
int dp[N][N],id[N][N];
bool vis[N][N];
bitset<N*N> p[N][N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,cnt=0,mx=0,mn=0;
    cin >> m >> n;
    for (int i=1;i<=n;i++) cin >> s[i];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (s[i][j-1]!='P' || vis[i][j]) continue;
            cnt++;
            queue <pi> q;
            q.emplace(i,j);
            while (!q.empty()){
                auto [ni,nj]=q.front();
                q.pop();
                if (s[ni][nj-1]!='P' || vis[ni][nj]) continue;
                vis[ni][nj]=1;
                id[ni][nj]=cnt;
                if (ni>1) q.emplace(ni-1,nj);
                if (nj>1) q.emplace(ni,nj-1);
                if (ni<n) q.emplace(ni+1,nj);
                if (nj<m) q.emplace(ni,nj+1);
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (s[i][j-1]=='T') continue;
            dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
            if (dp[i-1][j-1]<=dp[i-1][j] && dp[i-1][j-1]<=dp[i][j-1]){
                p[i][j]=p[i-1][j-1];
                for (int k=0;k<dp[i][j];k++) {
                    p[i][j][id[i-k][j]]=1;
                    p[i][j][id[i][j-k]]=1;
                }
            }
            else if (dp[i-1][j]<=dp[i-1][j-1] && dp[i-1][j]<=dp[i][j-1]){
                p[i][j]=p[i-1][j];
                for (int k=0;k<dp[i][j];k++) {
                    p[i][j][id[i-k][j-dp[i][j]+1]]=1;
                    p[i][j][id[i][j-k]]=1;
                }
            }
            else if (dp[i][j-1]<=dp[i-1][j-1] && dp[i][j-1]<=dp[i-1][j]){
                p[i][j]=p[i][j-1];
                for (int k=0;k<dp[i][j];k++) {
                    p[i][j][id[i-k][j]]=1;
                    p[i][j][id[i-dp[i][j]+1][j-k]]=1;
                }
            }
            p[i][j][0]=1;
            int np=p[i][j].count()-1;
            if (dp[i][j]>mx){
                mx=dp[i][j];
                mn=np;
            }
            else if (dp[i][j]==mx) mn=min(mn,np);
        }
    }
    cout << mx*mx << ' ' << mn;
}