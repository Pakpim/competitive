#include <bits/stdc++.h>
#define lc i*2+1
#define rc i*2+2
#define mid (l+r)/2
using namespace std;

using ll=long long;
const ll N=2e5+5;
ll n,m;
vector<ll> el[N];
vector<pair<ll,ll>> er[N];
ll sg[N*4],lazy[N*4];

void uplazy (ll l,ll r,ll i){ 
    if (l>r) return;
    sg[i]+=lazy[i];
    if (l!=r){
        lazy[lc]+=lazy[i];
        lazy[rc]+=lazy[i];
    }
    lazy[i]=0;
}

void up (ll tl,ll tr,ll tv,ll l=1,ll r=n,ll i=0){
    uplazy(l,r,i);
    if (tl>r || tr<l) return;
    if (l>=tl && r<=tr){
        lazy[i]+=tv;
        uplazy(l,r,i);
        return;
    }
    up(tl,tr,tv,l,mid,lc);
    up(tl,tr,tv,mid+1,r,rc);
    sg[i]=max(sg[lc],sg[rc]);
}

ll qu (ll tl,ll tr,ll l=1,ll r=n,ll i=0){
    uplazy(l,r,i);
    if (tl>r || tr<l) return 0;
    if (l>=tl && r<=tr) {
        return sg[i];
    }
    ll vl=qu(tl,tr,l,mid,lc),vr=qu(tl,tr,mid+1,r,rc);
    return max(vl,vr);
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (ll i=0;i<m;i++) {
        ll l,r,a;
        cin >> l >> r >> a;
        el[l].emplace_back(a);
        er[r].emplace_back(a,l);
    }
    ll sum=0,mx=0;
    for (ll i=1;i<=n;i++){
        for (auto a:el[i]) sum+=a;
        ll nv=max(0ll,qu(1,i-1));
        mx=max(mx,sum+nv);
        up(i,i,nv);
        for (auto [a,l]:er[i]){
            sum-=a;
            up(l,i,a);
        }
    }
    cout << mx;
}