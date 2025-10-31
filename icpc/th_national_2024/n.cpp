#include <bits/stdc++.h>
using namespace std;

using ll =long long;
const ll N=200005;
vector <ll> f,v;
ll cnt[N],ans[N];
bool found=0;

ll bp (ll a,ll b ,ll m){
    ll re=1;
    while (b){
        if (b&1) re=(re*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return re;
}

void cal (ll x,ll m){
    for (ll i= 0;i<m-1;i++){
        v.emplace_back(bp(x,i,m));
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    for (ll i=1;i<n;i++){
        if ((n-1)%i==0) f.emplace_back(i);
    }
    // cout << " => ";
    // for (auto e:f) cout << e << ' ';
    // cout << '\n';
    for (ll i=1;i<n;i++){
        for (auto e:f){
            if (bp(i,e,n)==1){
                cnt[e]++;
                if (!found && e==n-1){
                    found=1;
                    cal(i,n);
                }
                break;
            }
        }
    }
    // cout << " => ";
    // for (auto e:v) cout << e << ' ';
    // cout << '\n';
    for (auto e:f){
        for (ll i=0;i<e;i++){
            ans[v[i*(n-1)/e]]+=cnt[e]*(n-1)/e;
        }
    }
    for (ll i=1;i<n;i++) cout << ans [i] << ' ';
}