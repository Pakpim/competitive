#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=20005;
ll dp1[2][N],dp2[2][N],w[N],l[N];
int mx1[N],mx2[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> w[i] >> l[i];
    }
    for (int i=1;i<=n;i++){
        int a=i&1,b=!a;
        for (int j=1;j<=i;j++){
            if (i-1>=j) dp1[a][j]=dp1[b][j];
            else dp1[a][j]=1e18;
            if (dp1[b][j-1]<=l[i]) {
                dp1[a][j]=min(dp1[a][j],dp1[b][j-1]+w[i]);
                mx1[i]=max(mx1[i],j);
            }
            // cout << i << ' ' << j << ' ' << a << ' ' << b << " => " << dp1[a][j] << ' ' << dp1[b][j] << '\n';
        }
        // cout << " = " << mx1[i] << "\n\n";
    }
    dp2[0][0]=dp2[1][0]=1e18;
    for (int i=n;i>0;i--){
        int a=i&1,b=!a;
        for (int j=1;j<=n-i+1;j++){
            if (n-i>=j) dp2[a][j]=dp2[b][j];
            else dp2[a][j]=-1;
            if (dp2[b][j-1]>=w[i]) dp2[a][j]=max(dp2[a][j],min(dp2[b][j-1]-w[i],l[i]));
            if (dp2[a][j]!=-1) mx2[i]=max(mx2[i],j);
            // cout << i << ' ' << j << ' ' << a << ' ' << b << " => " << dp2[a][j] << ' ' << dp2[b][j] << '\n';
        }
        // cout << " = " << mx2[i] << "\n\n";
    }
    int ans=0;
    vector<int> v;
    for (int i=1;i<n;i++){
        if (ans<mx1[i]+mx2[i+1]){
            v.clear();
            ans=mx1[i]+mx2[i+1];
        }
        if (ans==mx1[i]+mx2[i+1]) v.emplace_back(i);
    }
    cout << ans << '\n';
    for (auto e:v) cout << e << ' ';
}