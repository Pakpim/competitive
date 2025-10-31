#include <bits/stdc++.h>
#define lll __int128_t
#define all(x) (x).begin(), (x).end()
#define lc i*2+1
#define rc i*2+2
#define mid (l+r)/2
using namespace std;
using ll=unsigned long long;
const char nl = '\n';
const ll N=5e5+5;

ll a[N],sg[N*4][2],cnt[N*4][2],lz[N*4][3];
ll b[N];
bool fc[N*4],sgc[N*4];

void uplazy(ll l,ll r,ll i){
    sg[i][0]+=lz[i][0]*cnt[i][0];
    sg[i][1]+=lz[i][1]*cnt[i][1];
    if (fc[i]){
        cnt[i][sgc[i]]=r-l+1;
        cnt[i][sgc[i]^1]=0;
        sg[i][sgc[i]]+=sg[i][sgc[i]^1] + lz[i][2]*(r-l+1);
        sg[i][sgc[i]^1]=0;
    }
    if (l<r){
        for (ll k=lc;k<=rc;k++){
            if (fc[k]){
                lz[k][2]+=lz[i][sgc[k]]+lz[i][2];
            }
            else{
                for (ll j=0;j<3;j++){
                    lz[k][j]+=lz[i][j];
                }
                fc[k]=fc[i];
            }
            if (fc[i]) sgc[k]=sgc[i];
        }
    }
    lz[i][0]=0;
    lz[i][1]=0;
    lz[i][2]=0;
    fc[i]=0;
}

void build(ll l,ll r,ll i){
    if (l==r){
        sg[i][0]=a[l];
        cnt[i][0]=1;
        return;
    }
    build(l,mid,lc);
    build(mid+1,r,rc);
    sg[i][0]=sg[lc][0]+sg[rc][0];
    sg[i][1]=sg[lc][1]+sg[rc][1];
    cnt[i][0]=cnt[lc][0]+cnt[rc][0];
    cnt[i][1]=cnt[lc][1]+cnt[rc][1];
    return;
}

ll qu (ll tl,ll tr,ll c,ll l,ll r,ll i){
    uplazy(l,r,i);
    if (l>tr || r<tl){
        return 0;
    }
    if (l>=tl && r<=tr){
        return sg[i][c];
    }
    return qu(tl,tr,c,l,mid,lc)+qu(tl,tr,c,mid+1,r,rc);
}

void up1 (ll tl,ll tr,ll c,ll l,ll r,ll i){
    uplazy(l,r,i);
    if (l>tr || r<tl){
        return;
    }
    if (l>=tl && r<=tr){
        fc[i]=1;
        sgc[i]=c;
        uplazy(l,r,i);
        return;
    }
    up1(tl,tr,c,l,mid,lc);
    up1(tl,tr,c,mid+1,r,rc);
    sg[i][0]=sg[lc][0]+sg[rc][0];
    sg[i][1]=sg[lc][1]+sg[rc][1];
    cnt[i][0]=cnt[lc][0]+cnt[rc][0];
    cnt[i][1]=cnt[lc][1]+cnt[rc][1];
    return;
}

void up2 (ll tl,ll tr,ll c,ll x,ll l,ll r,ll i){
    uplazy(l,r,i);
    if (l>tr || r<tl){
        return;
    }
    if (l>=tl && r<=tr){
        lz[i][c]+=x;
        uplazy(l,r,i);
        return;
    }
    up2(tl,tr,c,x,l,mid,lc);
    up2(tl,tr,c,x,mid+1,r,rc);
    sg[i][0]=sg[lc][0]+sg[rc][0];
    sg[i][1]=sg[lc][1]+sg[rc][1];
    cnt[i][0]=cnt[lc][0]+cnt[rc][0];
    cnt[i][1]=cnt[lc][1]+cnt[rc][1];
    return;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    ll n,q;
    cin >> n >> q;
    for (ll i=1;i<=n;i++) cin >> b[i], a[i]=b[i];
    build(1,n,0);
    // cout << " w => ";
    // for (ll i=0;i<=n;i++) cout << qu(i,i,0,1,n,0) << ' ';
    // cout << " b => ";
    // for (ll i=0;i<=n;i++) cout << qu(i,i,0,1,n,0) << ' ';
    // cout << '\n';
    while(q--){
        ll op,l,r,c;
        cin >> op >> l >> r >> c;
        if (op==1){
            // for (int i=l;i<=r;i++) up1(i,i,c,1,n,0);
            up1(l,r,c,1,n,0);
        }
        if (op==2){
            // ll x=qu(l,l,0,1,n,0)+qu(l,l,1,1,n,0) + c*(qu(r,r,0,1,n,0) + qu(r,r,1,1,n,0)) + r-l+1;
            ll x=a[l] + c*(a[r]) + ll(r-l+1);
            // cout << " 2 " << x << '\n';
            // for (int i=l;i<=r;i++) up2(i,i,c,x,1,n,0);
            up2(l,r,c,x,1,n,0);
        }
        if (op==3){
            cout << ll(qu(l,r,c,1,n,0)) << '\n';
        }
        // cout << " w => ";
        // for (ll i=0;i<=n;i++) cout << qu(i,i,0,1,n,0) << ' ';
        // cout << " b => ";
        // for (ll i=0;i<=n;i++) cout << qu(i,i,1,1,n,0) << ' ';
        // cout << '\n';
    }
}

/*
5 9
1 2 3 4 5
1 2 4 1
1 3 3 0
3 3 5 1
2 1 4 0
2 3 4 1
1 2 5 1
3 1 5 0
3 1 5 1
3 2 3 1
*/
