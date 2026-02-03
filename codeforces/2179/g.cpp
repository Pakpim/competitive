#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=105;
ll dis[N*N][3], a[N][N];
mt19937 gen((std::time(nullptr)));

ll ask (ll l ,ll r){
    ll re;
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    cin >> re;
    return re;
}

void solve(){
    ll n;
    cin >> n;
    vector<pair<ll,ll>> v0;
    ll c0=1;
    for (ll i=1;i<=n*n;i++) {
        if (i==c0) continue;
        ll nv=ask(c0,i);
        v0.emplace_back(nv, i);
        dis[i][0]=nv;
    }
    dis[c0][0]=0;
    sort(v0.begin(), v0.end());
    auto [d1,c1]=v0.back();
    ll mx=-1e9, c2=-1;
    if (v0.back().first==(n-1)+(n-1)){
        c1=c0;
        for (int i=i;i<=n*n;i++) dis[i][1]=dis[i][0];
        c0=v0[v0.size()-2].second;
        for (int i=1;i<=n*n;i++){
            int nv=ask(c0,i);
            dis[i][0]=nv;
            if (dis[i][1]==n-1){
                if (mx<dis[i][0]){
                    // cout << " ?? " << mx << " " << i << '\n';
                    mx=dis[i][0];
                    c2=i;
                }
            }
        }
    }
    else{
        dis[c1][1]=0;
        for (ll i=1;i<=n*n;i++){
            if (i==c1) continue;
            ll nv=ask(c1,i);
            dis[i][1]=nv;
            if (nv==n-1){
                // cout << " okok " << i << ' ' << dis[i][0] << '\n';
                if (mx<dis[i][0]){
                    // cout << " ?? " << mx << " " << i << '\n';
                    mx=dis[i][0];
                    c2=i;
                }
            }
        }
    }
    dis[c2][2]=0;
    for (ll i=1;i<=n*n;i++){
        if (i==c2) continue;
        ll nv=ask(c2,i);
        dis[i][2]=nv;
    }
    for (ll i=1;i<=n*n;i++){
        ll nx=(dis[i][1]+dis[i][2]-n+1)/2;
        ll ny=(dis[i][1]-dis[i][2]+n-1)/2;
        assert(nx>=0);
        assert(nx<n);
        assert(ny>=0);
        assert(ny<n);
        // cout << " !! " << nx << ' ' << ny << " : " << dis[i][1] << ' ' << dis[i][2] << '\n';
        a[nx+1][ny+1]=i;
    }
    cout << "!\n"; cout.flush();
    for (ll i=1;i<=n;i++){
        for (ll j=1;j<=n;j++) cout << a[i][j] << ' ';
        cout << '\n'; cout.flush();
    }
    cout << '\n'; cout.flush();
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--){
        solve();
    }
}