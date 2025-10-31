#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=6e5+5,M=1e9+7;
ll t[N],a[N],qs[N][5],ft[N],inv[N],mn[N][20],mx[N][20];
set<ll> z;

ll bp (ll a,ll b){
    ll re=1;
    while (b){
        if(b&1) re=(re*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return re;
}

ll ncr (ll n,ll r){
    return (((ft[n]*inv[r])%M)*inv[n-r])%M;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m,s;
    cin >> n >> m >> s;
    ft[0]=1;
    for (ll i=1;i<=n+m;i++) ft[i]=(ft[i-1]*i)%M;
    inv[n+m]=bp(ft[n+m],M-2);
    for (ll i=n+m-1;i>=0;i--) inv[i]=((inv[i+1])*(i+1))%M;
    for (int i=0;i<s;i++){
        ll a;
        cin >> a;
        z.emplace(a);
    }
    for (ll i=1;i<=n;i++){
        cin >> t[i];
        ll g=__gcd(i,n),f=z.count(t[i]%m);
        if (g==1 && !f) a[i]=1;
        else if (g>1 && f) a[i]=0;
        else a[i]=2;
        qs[i][0]=qs[i-1][0];
        qs[i][1]=qs[i-1][1];
        qs[i][2]=qs[i-1][2];
        qs[i][a[i]]++;
        mn[i][0]=mx[i][0]=t[i];
    }
    for (int i=1;i<20;i++){
        for (int j=1;j<=n-(1<<i)+1;j++){
            mn[j][i]=min(mn[j][i-1],mn[j+(1<<(i-1))][i-1]);
            mx[j][i]=max(mx[j][i-1],mx[j+(1<<(i-1))][i-1]);
        }
    }
    int q;
    cin >> q;
    while (q--){
        int l,r,md;
        cin >> l >> r >> md;
        ll ans[3],nmx=0;
        ll sz=r-l+1;
        ll tmp=log2(sz);
        ll mnt=min(mn[l][tmp],mn[r-(1<<tmp)+1][tmp]),mxt=max(mx[l][tmp],mx[r-(1<<tmp)+1][tmp]);
        for (int i=0;i<3;i++) ans[i]=qs[r][i]-qs[l-1][i],nmx=max(nmx,ans[i]);
        cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << mxt-mnt;
        if (md==1){
            cout << ' ' << ncr(n+m,nmx);
        }
        cout << '\n';
    }
    
}