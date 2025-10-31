#include <bits/stdc++.h>
using namespace std;

const int N=1005;
int l[N][N],r[N][N],u[N][N],d[N][N];
string s[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,m,ans=0;
        cin >> n >> m;
        for (int i=1;i<=n;i++) cin >> s[i];
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (s[i][j-1]=='0') continue;
                l[i][j]=l[i][j-1]+1;
                u[i][j]=u[i-1][j]+1;
            }
        }
        for (int i=n;i>0;i--){
            for (int j=m;j>0;j--){
                if (s[i][j-1]=='0') continue;
                r[i][j]=r[i][j+1]+1;
                d[i][j]=d[i+1][j]+1;
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                vector<int> v={l[i][j],r[i][j],u[i][j],d[i][j]};
                sort(v.begin(),v.end());
                // cout << i << ' ' << j << " => " << l[i][j] << ' ' << r[i][j] << ' ' << u[i][j] << ' ' << d[i][j] << '\n';
                ans=max(ans,v[2]+v[3]-1);
            }
        }
        cout << ans << '\n';
        for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) l[i][j]=r[i][j]=u[i][j]=d[i][j]=0;
    }
}