#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=2e5+5;
ll qs[N],a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,t;
    cin >> n >> t;
    for (int i=1;i<=n;i++) cin >> a[i];
    while (t--){
        ll l,r;
        cin >> l >> r;
        qs[l]++;
        qs[r+1]--;
    }
    for (int i=1;i<=n;i++){
        qs[i]+=qs[i-1];
    }
    sort(a+1,a+n+1);
    sort(qs+1,qs+n+1);
    ll ans = 0;
    for (int i=1;i<=n;i++){
        ans+=a[i]*qs[i];
    }
    cout << ans;
}