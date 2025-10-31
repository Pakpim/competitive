#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=705;
int a[N][N],f[N*N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,m;
        cin >> n >> m;
        for (int i=0;i<=n*m;i++) f[i]=0;
        for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
            cin >> a[i][j];
            f[a[i][j]]=max(f[a[i][j]],1);
            if (a[i][j]==a[i-1][j] || a[i][j]==a[i][j-1]) f[a[i][j]]=2;
        }
        int mx=0,sum=0;
        for (int i=0;i<=n*m;i++){
            int nv=f[i];
            mx=max(mx,nv);
            sum+=nv;
        }
        cout << sum-mx << '\n';
    }
}