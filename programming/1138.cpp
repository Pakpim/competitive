#include <bits/stdc++.h>
#define mid (l+r)/2
#define lc i*2+1
#define rc i*2+2
using namespace std;

using ll=long long;
const int N=1e5+5;
ll sg[N*4],n;

void up (ll p,ll v,ll l=0,ll r=n,ll i=0){
    if (l>p || r<p) return;
    if (l==r){
        sg[i]=v;
        return;
    }
    if (p<=mid) up(p,v,l,mid,lc);
    else up(p,v,mid+1,r,rc);
    sg[i]=max(sg[lc],sg[rc]);
}

ll qu (ll tl,ll tr,ll l=0,ll r=n,ll i=0){
    if (tl>r || tr<l) return -1e18;
    if (tl<=l && tr>=r) return sg[i];
    return max(qu(tl,tr,l,mid,lc),qu(tl,tr,mid+1,r,rc));
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll k,s,ans=0;
    cin >> n >> k >> s;
    vector<pair<ll,ll>> q,v;
    v.emplace_back(s,0);
    for (ll i=1;i<=n;i++){
        ll x,a;
        cin >> x >> a;
        q.emplace_back(x,a);
        v.emplace_back(x,i);
    }
    sort(v.begin(),v.end());
    for (int i=0;i<n*4;i++) sg[i]=-1e18;
    ll p=lower_bound(v.begin(),v.end(),make_pair(s,0ll))-v.begin();
    up(p,0);
    for (ll i=1;i<=n;i++){
        auto [x,a]=q[i-1];
        ll tl=lower_bound(v.begin(),v.end(),make_pair(x-k,0ll))-v.begin();
        ll tr=upper_bound(v.begin(),v.end(),make_pair(x+k,ll(1e18)))-v.begin()-1;
        ll nv=qu(tl,tr);
        if (nv!=1e18){
            nv+=a;
            ans=max(ans,nv);
            p=lower_bound(v.begin(),v.end(),make_pair(x,i))-v.begin();
            up(p,nv);
        }
    }
    cout << ans;
}