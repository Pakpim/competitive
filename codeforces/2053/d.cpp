#include <bits/stdc++.h>
#define mid (l+r)/2
#define lc i*2+1
#define rc i*2+2
using namespace std;

using ll=long long;
using vp=vector<pair<ll,ll>>;
const ll N=2e5+5,M=998244353;
ll sg[N*4],n,aa[N],bb[N];
map<ll,ll> ma,mb;

ll bp (ll a,ll b){
    ll re=1;
    while (b){
        if (b&1) re=(re*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return re;
}

void build (vp &a,vp&b,int l=0,int r=n-1,int i=0){
    if (l>r){
        sg[i]=1;
        return;
    }
    if (l==r){
        sg[i]=min(a[l].first,b[l].first);
        return;
    }
    build(a,b,l,mid,lc);
    build(a,b,mid+1,r,rc);
    sg[i]=(sg[lc]*sg[rc])%M;
    // cout <<l << ' ' << r << ' ' <<i << " => " << sg[i] << ' ' << sg[lc] << ' ' << sg[rc] << '\n';
}

void up (vp &a,vp &b,int p,int l=0,int r=n-1,int i=0){
    if (r<p || l>p) return;
    if (l==r){
        // cout << " ? " << l << ' ' << p << ' ' << a[l].first << ' ' << b[l].first << '\n';
        sg[i]=min(a[l].first,b[l].first);
        return;
    }
    if (p<=mid) up(a,b,p,l,mid,lc);
    else up(a,b,p,mid+1,r,rc);
    sg[i]=(sg[lc]*sg[rc])%M;
    // cout << '\n' <<l << ' ' << r << ' ' <<i << " => " << sg[i] << ' ' << sg[lc] << ' ' << sg[rc] << '\n';
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll q;
        cin >> n >> q;
        vector<pair<ll,ll>> va(n),vb(n);
        for (int i=0;i<n*4;i++) sg[i]=1;
        for (ll i=1;i<=n;i++){
            cin >> va[i-1].first;
            aa[i]=va[i-1].first;
            va[i-1].second=i;
        }
        for (ll i=1;i<=n;i++){
            cin >> vb[i-1].first;
            bb[i]=vb[i-1].first;
            vb[i-1].second=i;
        }
        sort(va.begin(),va.end());
        sort(vb.begin(),vb.end());
        for (ll i=1;i<=n;i++){
            if (i==n || va[i-1].first!=va[i].first){
                ma[va[i-1].first]=i-1;
            }
            if (i==n || vb[i-1].first!=vb[i].first){
                mb[vb[i-1].first]=i-1;
            }
        }
        // ll pr=1;
        // for (ll i=0;i<n;i++) pr=(pr*min(va[i].first,vb[i].first))%M;
        // cout << pr << ' ';
        build(va,vb);
        cout << sg[0] << ' ';
        while (q--){
            ll o,x;
            cin >> o >> x;
            ll idx;
            if (o==1){
                idx=ma[aa[x]];
                va[idx].first++;
                if (va[idx].first==aa[x]) ma[aa[x]]--;
                else ma.erase(aa[x]);
                ma[aa[x]+1]=max(ma[aa[x]+1],idx);
                aa[x]++;
            }
            else{
                idx=mb[bb[x]];
                vb[idx].first++;
                if (vb[idx].first==bb[x]) mb[bb[x]]--;
                else mb.erase(bb[x]);
                mb[bb[x]+1]=max(mb[bb[x]+1],idx);
                bb[x]++;
            }
            up(va,vb,idx);
            cout << sg[0] << ' ';
        }
        cout << '\n';
    }
}

/*
1
13 8
7 7 6 6 5 5 5 2 2 3 4 5 1
1 4 1 9 6 6 9 1 5 1 3 8 4
2 2
2 11
2 4
2 4
1 7
1 1
2 12
1 5
*/