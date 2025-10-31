#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=1505;
int a[N],mx[N][N];
bool f[N*N];
vector<pair<int,int>> v[N*N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int l,n,m;
        cin >> l >> n >> m;
        for (int i=1;i<=l;i++) cin >> a[i];
        for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
            int b;
            cin >> b;
            v[b].emplace_back(i,j);
        }
        int r=l;
        for (int i=1;i<=l;i++){
            if (!f[a[i]]) f[a[i]]=1;
            else{
                r=i-1;
                break;
            }
        }
        for (int i=r;i>0;i--){
            for (auto [r,c]:v[a[i]]) {
                if (mx[i+1][r+1]<=c) mx[i][r]=max(mx[i][r],c);
            }
            for (int j=n;j>0;j--) mx[i][j]=max(mx[i][j],mx[i][j+1]);
            // cout << i << " => ";
            // for (int j=1;j<=n;j++) cout << mx[i][j] << ' ';
            // cout << '\n';
        }
        bool w=0;
        for (auto [r,c]:v[a[1]]) if (mx[2][r+1]<=c) w=1;
        if (w) cout << "T\n";
        else cout << "N\n";
        for (int i=1;i<=n*m;i++) f[i]=0,v[i].clear();
        for (int i=1;i<=l;i++) for (int j=1;j<=n;j++) mx[i][j]=0;
        
    }
}