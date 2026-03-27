#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5;
pair<ll,ll> a[N];
ll b[N], mx[N][2], ans[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    for (int i=1;i<=n+1;i++) cin >> a[i].first, a[i].second = i;
    for (int i=1;i<=n;i++) cin >> b[i];
    sort(a+1,a+n+2);
    sort(b+1,b+n+1);
    for (int i=1;i<=n;i++) mx[i][0]=max(mx[i-1][0],a[i].first-b[i]);
    for (int i=n;i>0;i--) mx[i][1]=max(mx[i+1][1],a[i+1].first-b[i]);
    for (int i=1;i<=n+1;i++) ans[a[i].second] = max(mx[i-1][0],mx[i][1]);
    for (int i=1;i<=n+1;i++) cout << ans[i] << ' ';
}