#include <bits/stdc++.h>
#define mid (l+r)/2
#define lc i*2+1
#define rc i*2+2
using namespace std;

using ll=long long;
using db=double;
const ll N=2e5+5,P=1e5;
ll ar[N],sg[N*4],n;

void build(int l=1,int r=n-1,int i=0){
    if (l>r) return;
    if (l==r){
        sg[i]=abs(ar[l]-ar[l+1]);
        return;
    }
    build(l,mid,lc);
    build(mid+1,r,rc);
    sg[i]=__gcd(sg[lc],sg[rc]);
}

int qu(int tl,int tr,int l=1,int r=n-1,int i=0){
    if (r<tl || l>tr) return 0;
    if (l>=tl && r<=tr) return sg[i];
    return __gcd(qu(tl,tr,l,mid,lc),qu(tl,tr,mid+1,r,rc));
}

void solve(){
    int q;
    cin >> n >> q;
    for (int i=1;i<=n;i++) cin >> ar[i];
    build();
    while (q--){
        int l,r;
        cin >> l >> r;
        if (l==r) cout << "0 ";
        else cout << qu(l,r-1) << ' ';
    }
    cout << '\n';
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}