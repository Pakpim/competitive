#include <bits/stdc++.h>
#define mid (l+r)/2
#define lc i*2+1
#define rc i*2+2
using namespace std;

using ll = long long;
const int N=1e5+5;
ll sg[N*4],lz[N*4],n,q;

void uplz(int l,int r,int i){
    sg[i]+=lz[i]*(r-l+1);
    if (l<r){
        lz[lc]+=lz[i];
        lz[rc]+=lz[i];
    }
    lz[i]=0;
}

void up (int tl,int tr,ll v, int l=1,int r=n,int i=0){
    uplz(l,r,i);
    if (tl>r || tr<l) return;
    if (l>=tl && r<=tr){
        lz[i]+=v;
        uplz(l,r,i);
        return;
    }
    up(tl,tr,v,l,mid,lc);
    up(tl,tr,v,mid+1,r,rc);
    sg[i]=sg[lc]+sg[rc];
}

ll qu (int tl,int tr, int l=1,int r=n,int i=0){
    uplz(l,r,i);
    ll tmp;
    if (tl>r || tr<l) tmp= 0;
    else if (l>=tl && r<=tr) tmp=sg[i];
    else tmp = qu(tl,tr,l,mid,lc)+ qu(tl,tr,mid+1,r,rc);
    // cout << " ? " << l << ' ' << r << ' ' << tmp << '\n';
    return tmp;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        for (int i=0;i<n*4;i++) sg[i]=lz[i]=0;
        cin >> n >> q;
        while (q--){
            int o;
            cin >> o;
            if (!o){
                ll l,r,v;
                cin >> l >> r >> v;
                up(l,r,v);
            }
            else{
                ll l,r;
                cin >> l >> r;
                cout << qu(l,r) << '\n';
            }
        }
    }
}