#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5;
ll a[N][20], b[N][20], sum[N];

void solve(){
    ll n,q;
    cin >> n >> q;
    for (int i=0;i<20;i++) for (int j=0;j<=n;j++) a[j][i]=b[j][i]=0;
    for (int i=0;i<=n;i++) sum[i]=0;
    while (q--){
        ll l,r;
        cin >> l >> r;
        for (int i=0;(1<<i)<=r-l+1;i++){
            ll nr=(r-l+1ll-(1<<i))/(1ll<<(i+1ll));
            nr++;
            // cout << "? " << nr << ' ' << (nr<<(i+1)) << '\n';
            nr=(nr<<(i+1)) + (1<<i);
            nr+=l-1;
            ll nl=(1<<i)+l-1;
            if (nl<=n) a[nl][i]+=(1<<i);
            if (nr<=n) a[nr][i]-=(1<<i);
            if (nl<=n) b[nl][i]+=(-l+1)*(1<<i);
            if (nr<=n) b[nr][i]-=(-l+1)*(1<<i);
            // cout << i << " ? " << l << ' ' << r << " => " << nl << ' ' << nr << " : " << (1<<i) << ' ' << -l+i << '\n';
        }
    }
    for (int i=0, k=2;1<<i<=n;i++, k<<=1){
        for (int j=1;j<=n;j++) {
            if (j-k>=0) a[j][i]+=a[j-k][i];
            if (j-k>=0) b[j][i]+=b[j-k][i];
            sum[j]+=j*a[j][i]+b[j][i];
        }
    }
    // for (int i=0;1<<i<=n;i++){
    //     for (int j=1;j<=n;j++) {
    //         cout << a[j][i] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    // for (int i=0;1<<i<=n;i++){
    //     for (int j=1;j<=n;j++) {
    //         cout << b[j][i] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    for (int i=1;i<=n;i++) cout << sum[i] << ' ';
    cout << '\n';
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}