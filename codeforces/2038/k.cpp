#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using db=double;
const ll N=1e6+5;
deque<pair<ll,ll>> dq[2];
ll n,a[2][N],x[2];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> x[0] >> x[1];
    ll sum=0;
    for (ll t=0;t<2;t++){
        for (ll i=1;i<=n;i++) a[t][i]=__gcd(i,x[t]);
        for (ll i=n;i>1;i--){
            ll nv=a[t][i]-a[t][i-1],nn=1;
            // cout << " --> " << t << ' ' << i << " : ";
            sum+=nv;
            while (!dq[t].empty() && db(dq[t].front().first)/db(dq[t].front().second)<=db(nv)/db(nn)){
                auto [fv,fn]=dq[t].front();
                dq[t].pop_front();
                sum+=nv*fn;
                nv+=fv;
                nn+=fn;
            }
            dq[t].emplace_front(nv,nn);
            // for (auto [f,s]:dq[t]) cout << f << '/' << s << ' ';
            // cout << '\n';
        }
    }
    // cout << " => ";
    // for (auto [f,s]:dq[0]) cout << f << '/' << s << ' ';
    // cout << "\n => ";
    // for (auto [f,s]:dq[1]) cout << f << '/' << s << ' ';
    // cout << "\n = " << sum << '\n';
    ll nv=a[0][1]+a[1][1], nn=1;
    sum+=nv;
    while (!dq[0].empty() || !dq[1].empty()){
        if (dq[0].empty()){
            auto [fv,fn]=dq[1].front();
            dq[1].pop_front();
            sum+=nv*fn;
            nv+=fv;
            nn+=fn;
        }
        else if (dq[1].empty() || db(dq[0].front().first)/db(dq[0].front().second) < db(dq[1].front().first)/db(dq[1].front().second)){
            auto [fv,fn]=dq[0].front();
            dq[0].pop_front();
            sum+=nv*fn;
            nv+=fv;
            nn+=fn;
        }
        else {
            auto [fv,fn]=dq[1].front();
            dq[1].pop_front();
            sum+=nv*fn;
            nv+=fv;
            nn+=fn;
        }
    }
    cout << sum;
}