#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5;
ll a[N];
vector<ll> v;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,cnt=0,s1=0,s2=0,ans=1e18;
    cin >> n;
    for (ll i=0;i<n;i++){
        cin >> a[i];
        a[i]-=i;
        v.emplace_back(a[i]);
        s1+=a[i];
        // cout << i << ' ' << a[i] << '\n';
    }
    cnt=n;
    sort(v.begin(),v.end());
    for (auto e:v){
        ll nv = s1 - e*cnt + e*(n-cnt) -s2;
        ans=min(ans,nv);
        cnt--;
        s1-=e;
        s2+=e;
        // cout << ans << ' ' << nv << ' ' << e << ' ' << cnt << ' ' << s1 << ' ' << s2 << '\n';
    }
    cout << ans;
}