#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using db=double;
using pll=pair<ll,ll>;
const ll N=4e5+5;
ll a[N],ps[N];
set<ll>s;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,k,sum=0;
    bool ok=0;
    cin >> n >> k;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
        sum+=a[i];
        ps[i]=ps[i-1]+a[i];
    }
    k%=sum;
    s.emplace(0);
    for (ll i=1;i<=n;i++){
        s.emplace(sum-ps[i]);
    }
    // for (auto e:s) cout << e << ' '; cout << '\n';
    for (ll i=0;i<=n;i++){
        // cout << i << ' ' << ps[i] << " => " << ((k-ps[i])%sum +sum)%sum << '\n';
        // (a+b)%sum=k%sum
        if (s.count(((k-ps[i])%sum +sum)%sum)){
            ok=1;
        }
    }
    if (ok) cout << "Yes";
    else cout << "No";
}