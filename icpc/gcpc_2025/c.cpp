#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5;
ll a[N],cnt[N];
bool f[N];

struct fenw{
    vector<ll> v;
    fenw(){v.resize(N,0);}
    ll qu (ll i){
        ll re=0;
        for (;i;i-=i&-i) re+=v[i];
        return re;
    }
    void up(ll i, ll nv){
        for (;i<N;i+=i&-i) v[i]+=nv;
    }
    void clear(){
        for (auto &e:v) e=0;
    }
}fw;

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,t;
    cin >> n >> t;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        fw.up(i,a[i]-a[i-1]);
    }
    for (int i=1;i<=n;i++){

        if (i&1){
            ll nv=fw.qu(i)-fw.qu(i-1);
            if (nv) {
                f[i]=1;
                fw.up(i+1,1);
                ll r=min(n+1,i+nv+1);
                fw.up(r,-1);
                cnt[r-1]++;
            }
        }
    }

}