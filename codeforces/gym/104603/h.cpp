#include <bits/stdc++.h>

using namespace std;

using ll=long long;
const ll N=1005;
ll a[N][N],r[N],c[N];
pair<ll,ll> p[N*N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,ans=0;
    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) {
            cin >> a[i][j];
            p[a[i][j]]={i,j};
        }
    }
    for (int i=n*n;i>0;i--){
        auto [nr,nc] = p[i];
        ll vr,vc;
        vr = max(r[nr],c[nc]+1);
        vc = max(c[nc],r[nr]+1);
        r[nr] = max(r[nr],vr);
        c[nc] = max(c[nc],vc);
        ans=max({ans,vr,vc});
    }
    cout << ans;
}