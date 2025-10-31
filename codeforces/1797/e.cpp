#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=100005,A=5000005,K=6;

ll ar[N],sum[N*4],val[N*4],mx[N*4],f[K][A],h[A],qs[N][25],nx[N],bf[N];
bool vis[A];
vector<ll> prime,g[A];

tuple<ll,ll,ll> cal(ll a,ll b){
    if (a==-1) return {0,0,b};
    if (b==-1) return {0,0,a};
    ll c1=0,c2=0;
    bool sw=0;
    if (h[a]<h[b]) swap(a,b),sw=1;
    for (int i=K-1;i>=0;i--){
        if (h[f[i][a]]>h[b]) {
            a=f[i][a];
            c1+=1<<i;
        }
    }
    if (h[a]>h[b]) a=f[0][a],c1++;
    for (int i=K-1;i>=0;i--){
        if (f[i][a]!=f[i][b]){
            a=f[i][a];
            b=f[i][b];
            c1+=1<<i;
            c2+=1<<i;
        }
    }
    if (a!=b) {
        a=f[0][a];
        c1++; c2++;
    }
    if (!sw) return {c1,c2,a};
    else return {c2,c1,a};
} 

void build(ll l,ll r,ll i){
    if (l>r) return;
    if (l==r){
        sum[i]=0;
        val[i]=ar[l];
        mx[i]=h[ar[l]];
        return;
    }
    ll mid=(l+r)/2,lc=i*2+1,rc=i*2+2,sz1=mid-l+1,sz2=r-mid;
    build(l,mid,lc);
    build(mid+1,r,rc);
    auto [c1,c2,v] = cal(val[lc],val[rc]);
    sum[i]=sum[lc]+sum[rc]+c1*sz1+c2*sz2;
    val[i]=v;
    mx[i]=max(mx[lc],mx[rc]);
    return;
}

void up (ll l,ll r,ll i,ll tl,ll tr){
    if (mx[i]==0) return;
    if (r<tl || l>tr) return;
    if (l==r){
        val[i]=f[0][val[i]];
        mx[i]--;
        return;
    }
    ll mid=(l+r)/2,lc=i*2+1,rc=i*2+2,sz1=mid-l+1,sz2=r-mid;
    if (tl<=mid) up(l,mid,lc,tl,tr);
    if (tr>mid) up(mid+1,r,rc,tl,tr);
    auto [c1,c2,v] = cal(val[lc],val[rc]);
    sum[i]=sum[lc]+sum[rc]+c1*sz1+c2*sz2;
    val[i]=v;
    mx[i]=max(mx[lc],mx[rc]);
    return;
}

tuple<ll,ll,ll> qu (ll l,ll r,ll i,ll tl,ll tr){
    if (r<tl || l>tr) return {0,-1,0};
    ll mid=(l+r)/2,lc=i*2+1,rc=i*2+2;
    if (l>=tl && r<=tr) return {sum[i],val[i],r-l+1};
    if (mx[i]==0) return {0,1,r-l+1};
    auto [sum1,v1,sz1]=qu(l,mid,lc,tl,tr);
    auto [sum2,v2,sz2]=qu(mid+1,r,rc,tl,tr);
    auto [c1,c2,v3]=cal(v1,v2);
    if (v1==-1) return {sum2,v2,sz2};
    if (v2==-1) return {sum1,v1,sz1};
    return {sum1+sum2+c1*sz1+c2*sz2,v3,sz1+sz2};
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,q;
    f[0][1]=1;
    for (ll i=2;i<A;i++){
        if (vis[i]){
            for (auto e:prime){
                if (i%e==0){
                    ll gcd=__gcd(i/e,e);
                    f[0][i]=f[0][i/e]*f[0][e]*gcd/f[0][gcd];
                    // https://www.geeksforgeeks.org/eulers-totient-function/
                    break;
                }
            }
        }
        else{
            f[0][i]=i-1;
            for (ll j=i*2;j<A;j+=i) vis[j]=1;
            prime.emplace_back(i);
        }
        g[f[0][i]].emplace_back(i);
    }
    for (ll i=1;i<K;i++){
        for (ll j=1;j<A;j++){
            f[i][j]=f[i-1][f[i-1][j]];
        } 
    }
    queue <pair<ll,ll>> bfs;
    bfs.emplace(1,0);
    while (!bfs.empty()){
        auto [nn,nd]=bfs.front();
        bfs.pop();
        h[nn]=nd;
        for (auto e:g[nn]) bfs.emplace(e,nd+1);
    }
    cin >> n >> q;
    for (ll i=1;i<=n;i++) cin >> ar[i];
    build(1,n,0);
    while (q--){
        ll t,l,r;
        cin >> t >> l >> r;
        if (t==1) {
            up(1,n,0,l,r);
        }
        else{
            auto [ns,nv,nsz]=qu(1,n,0,l,r);
            cout << ns << '\n';
        }
    }
}

/*

*/