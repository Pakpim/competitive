#include <bits/stdc++.h>
#define mid (l+r)/2
#define lc i*2+1
#define rc i*2+2
using namespace std;

using ll=long long;
const ll N=2e5+5;
ll n,a[N],sg[N*4][4],mx[N*4][4];

void build (ll l=0,ll r=n-1,ll i=0){
    if (l>r) return;
    if (l==r){
        sg[i][0]=a[l]+l;
        sg[i][1]=-a[l]-l;
        sg[i][2]=-a[l]+l;
        sg[i][3]=a[l]-l;
        mx[i][0]=a[l]+l;
        mx[i][1]=-a[l]-l;
        mx[i][2]=-a[l]+l;
        mx[i][3]=a[l]-l;
        return;
    }
    build(l,mid,lc);
    build(mid+1,r,rc);
    for (int j=0;j<2;j++){
        ll tmp=-1;
        for (int k=lc;k<=rc;k++){
            if (sg[k][j*2]+sg[k][j*2+1]>tmp){
                tmp=sg[k][j*2]+sg[k][j*2+1];
                sg[i][j*2]=sg[k][j*2];
                sg[i][j*2+1]=sg[k][j*2+1];
            }
        }
        if (mx[lc][j*2]+mx[rc][j*2+1]>tmp){
            sg[i][j*2]=mx[lc][j*2];
            sg[i][j*2+1]=mx[rc][j*2+1];
        }
    }
    for (int j=0;j<4;j++) mx[i][j]=max(mx[lc][j],mx[rc][j]);
}

ll qu (ll tl,ll tr,ll ti,ll l=0,ll r=n-1,ll i=0){
    if (l>tr || r<tl) return -1e18;
    if (tl<=l && tr>=r) return sg[i][ti];
    return max(qu(tl,tr,ti,l,mid,lc),qu(tl,tr,ti,mid+1,r,rc));
}

void up (ll p,ll l=0,ll r=n-1,ll i=0){
    if (l>r) return;
    if (l==r){
        sg[i][0]=a[l]+l;
        sg[i][1]=-a[l]-l;
        sg[i][2]=-a[l]+l;
        sg[i][3]=a[l]-l;
        mx[i][0]=a[l]+l;
        mx[i][1]=-a[l]-l;
        mx[i][2]=-a[l]+l;
        mx[i][3]=a[l]-l;
        return;
    }
    if (p<=mid) up(p,l,mid,lc);
    else up(p,mid+1,r,rc);
    for (int j=0;j<2;j++){
        ll tmp=-1;
        for (int k=lc;k<=rc;k++){
            if (sg[k][j*2]+sg[k][j*2+1]>tmp){
                tmp=sg[k][j*2]+sg[k][j*2+1];
                sg[i][j*2]=sg[k][j*2];
                sg[i][j*2+1]=sg[k][j*2+1];
            }
        }
        if (mx[lc][j*2]+mx[rc][j*2+1]>tmp){
            sg[i][j*2]=mx[lc][j*2];
            sg[i][j*2+1]=mx[rc][j*2+1];
        }
    }
    for (int j=0;j<4;j++) mx[i][j]=max(mx[lc][j],mx[rc][j]);
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll q;
        cin >> n >> q;
        for (ll i=0;i<n*4;i++) for (int j=0;j<4;j++) sg[i][j]=-1e18;
        for (ll i=0;i<n;i++) cin >> a[i];
        build();
        // cout << '\n';
        // cout << " => " << sg[0][0] << ' ' << sg[0][1] << ' ' << sg[0][2] << ' ' << sg[0][3] << '\n';
        cout << max(sg[0][0]+sg[0][1],sg[0][2]+sg[0][3]) << '\n';
        while (q--){
            ll p,x;
            cin >> p >> x;
            p--;
            a[p]=x;
            up(p);
            // cout << " => " << sg[0][0] << ' ' << sg[0][1] << ' ' << sg[0][2] << ' ' << sg[0][3] << '\n';
            cout << max(sg[0][0]+sg[0][1],sg[0][2]+sg[0][3]) << '\n';
        }
    }
}

/*
1
5 3
1 2 3 4 5
3 7
1 4
5 2
*/