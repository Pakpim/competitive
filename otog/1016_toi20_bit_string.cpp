#include <bits/stdc++.h>
using namespace std;

using ll =long long;
const ll N=(1<<20);
ll a[N],dp[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q,c;
    string b;
    cin >> n >> q;
    for (int i=0;i<1<<n;i++){
        int c=0;
        cin >> b;
        for (int j=0;j<n;j++){
            c<<=1;
            if (b[j]=='1') c+=1;
        }
        cin >> a[c];
    }
    for (int i=1;i<1<<n;i++){
        dp[i]=-1e18;
        for (int j=0;j<n;j++){
            if (i&1<<j) dp[i]=max(dp[i],dp[i-(1<<j)]);
            if (j!=0 && i&1<<j && i&1<<(j-1)) dp[i]=max(dp[i],dp[i-(1<<j)-(1<<(j-1))]);
        }
        dp[i]+=a[i];
    }
    while (q--){
        c=0;
        cin >> b;
        for (int i=0;i<n;i++){
            c<<=1;
            if (b[i]=='1') c+=1;
        }
        cout << dp[c] << '\n';
    }
}