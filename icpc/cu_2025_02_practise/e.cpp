#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5;
ll a[N],qs[N],p[N],par[N],s[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k;
    tuple<ll,ll,ll> mx={-1e18,-1e18,-1e18};
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        qs[i]=qs[i-1]+a[i];
    }
    for (int i=n;i>0;i--){
        if (i+k-1<=n){
            s[i]=qs[i+k-1]-qs[i-1];
            par[i]=i;
            if (s[i]<s[i+1]){
                s[i]=s[i+1];
                par[i]=par[i+1];
            }
        }
        else{
            s[i]=-1e18;
            par[i]=i;
        }
    }
    for (int i=1;i+k<=n;i++){
        if (s[i]==-1e18) break;
        tuple<ll,ll,ll> nv={qs[i+k-1]-qs[i-1]+s[i+k],-i,-par[i+k]};
        mx=max(mx,nv);
    }
    auto [_,a,b] = mx;
    cout << -a << ' ' << -b;
}