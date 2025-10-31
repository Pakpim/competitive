#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using bs=bitset<6>;
const int N=55;
int b[N],qs[N],ans,n;
ll f[N];

void dfs(ll nb,int ni,int sum){
    if (sum+qs[ni]<=ans) return;
    ans=max(ans,sum);
    if (ni>=n) return;
    dfs(nb,ni+1,sum);
    ll xb=nb|1ll<<ni;
    if ((f[ni]&xb)==xb) dfs (xb,ni+1,sum+b[ni]);
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=0;i<n;i++) cin >> b[i];
    for (int i=n-1;i>=0;i--) qs[i]=qs[i+1]+b[i];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            ll ok; cin >> ok;
            f[i]|=(ok<<j);
        }
        // cout << i << " : " << bs(f[i]) << '\n';
    }
    dfs(0,0,0);
    cout << ans;
}