#include <bits/stdc++.h>
using namespace std;

using ll=long long;

const ll N=1e5+5;
ll d[N],a[N],n,m,b,w;

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
}fw1,fw2;


bool cal (ll x){
    fw1.clear();
    fw2.clear();
    ll cnt=0,sum=0,mx=0;
    map<ll,ll> mp;
    for (ll i=1;i<=n;i++){
        // cout << i << " : ";
        ll nv=(fw1.qu(a[i]-1) + 1)* w*2ll;
        if (!mp.count(a[i])){
            nv+=(fw2.qu(m)-fw2.qu(a[i])) *w*2ll;
            mx=max(mx,d[a[i]]);
            fw1.up(a[i],1ll);
        }
        // cout << sum << ' ' << mx << ' ' << nv << '\n';
        mp[a[i]]++;
        fw2.up(a[i],1);
        if (nv+sum+mx>x){
            cnt++;
            sum=cnt*b + 2ll*w;
            mx=d[a[i]];
            nv=0;
            for (auto [f,s]:mp){
                fw1.up(f,-1ll);
                fw2.up(f,-s);
            }
            assert(i!=0);
            mp.clear();
            mp[a[i]]++;
            fw1.up(a[i],1);
            fw2.up(a[i],1);
            if (sum+mx>x) return 0;
        }
        sum+=nv;
        assert(sum+mx<=x);
    }
    return 1;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> b >> w;
    for (ll i=1;i<=m;i++) cin >> d[i], d[i]+=d[i-1];
    for (ll i=1;i<=n;i++) cin >> a[i];
    ll l=0,r=1e18,mid,ans=r;
    while (l<=r){
        mid=l+(r-l)/2ll;
        bool yes=cal(mid);
        if (yes){
            ans=min(ans,mid);
            r=mid-1;
        }
        else l=mid+1;
    }
    cout << ans;
}