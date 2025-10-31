#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=3e5+5;
ll a[N],ps[N],psps[N],b[N],ps2[N],sum1[N]; 
ll n,q;

ll qu (ll p){
    ll re=0;
    ll l=0,r=n-1,mid,tg=0;
    while (l<=r){
        mid=(l+r)/2;
        if (sum1[mid] > p){
            r=mid-1;
        }
        else{
            tg=max(tg,mid);
            l=mid+1;
        }
    }
    // cout << " => " << p << ' ' << tg << '\n';
    re+=ps2[tg];
    re-=ps[tg]*(p-sum1[tg]);
    re+=psps[tg+p-sum1[tg]];
    re-=psps[tg];
    // cout << psps[tg+p-sum1[tg]] << '\n';
    return re;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (ll i=1;i<=n;i++) cin >> a[i],ps[i]=a[i]+ps[i-1];
    for (ll i=1;i<=n;i++) b[1]+=ps[i];
    for (ll i=1;i<=n;i++) sum1[i]=sum1[i-1]+(n-i+1);
    ps2[1]=b[1];
    for (ll i=2;i<=n;i++){
        b[i]=b[i-1]-a[i-1]*(n-i+2);
        ps2[i]=ps2[i-1]+b[i];
    }
    for (ll i=1;i<=n;i++){
        psps[i]=psps[i-1]+ps[i];
    }
    //  cout << "ps => ";
    // for (ll i=1;i<=n;i++) cout << ps[i] << ' ';
    // cout << '\n';
    // cout << "b => ";
    // for (ll i=1;i<=n;i++) cout << b[i] << ' ';
    // cout << '\n';
    cin >> q;
    while (q--){
        ll l,r;
        cin >> l >> r;
        // cout << " => " << qu(r) << ' ' << qu(l-1) << '\n';
        cout << qu(r)-qu(l-1) << '\n';
    }
}