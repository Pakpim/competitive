#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=505;
ll ar[N][N],qs[N][N];
string s[N];

void solve (){
    int n,m,k;
    ll sum=0;
    ll gcd=0;
    cin >> n >> m >> k;
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin >> ar[i][j];
    for (int i=1;i<=n;i++) cin >> s[i];
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++){
        qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        if (s[i][j-1]=='0') sum-=ar[i][j],qs[i][j]--;
        else sum+=ar[i][j],qs[i][j]++;
    }
    for (int i=k;i<=n;i++) for (int j=k;j<=m;j++){
        gcd=__gcd(gcd,qs[i][j]-qs[i-k][j]-qs[i][j-k]+qs[i-k][j-k]);
    }
    if (sum==0 || (gcd!=0 && sum%gcd==0)) cout << "YES\n";
    else cout << "NO\n";
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}