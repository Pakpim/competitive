#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using db=double;
const ll N=5e5+5;
ll a[2][N];
deque<pair<ll,ll>> dq[2];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n[2],sum=0;
    cin >> n[0] >> n[1];
    for (int t=0;t<2;t++){
        for (int i=0;i<=n[t];i++) cin >> a[t][i];
        for (int i=1;i<=n[t];i++) sum+=(a[t][i]-a[t][i-1])*(i+n[t^1]);
        sum+=a[t][0]*n[t^1];
        for (int i=n[t];i>0;i--){
            ll nv=a[t][i]-a[t][i-1],nc=1;
            sum-=nv;
            while (!dq[t].empty() && db(dq[t].front().first)/db(dq[t].front().second) <= db(nv)/db(nc)){
                auto [fv,fc]=dq[t].front();
                dq[t].pop_front();
                sum-=nc*fv;
                nv+=fv;
                nc+=fc;
            }
            dq[t].emplace_front(nv,nc);
        }
    }
    ll nv=0,nc=0;
    while (!dq[0].empty() || !dq[1].empty()){
        int tg=0;
        if (dq[0].empty() || (!dq[1].empty() && (dq[0].front().first)/db(dq[0].front().second) > db(dq[1].front().first)/db(dq[1].front().second))){
            tg=1;
        }
        auto [fv,fc]=dq[tg].front();
        dq[tg].pop_front();
        sum-=nc*fv;
        nv+=fv;
        nc+=fc;
    }
    cout << sum;
}