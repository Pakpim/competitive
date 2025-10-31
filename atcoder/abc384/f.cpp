#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using db=double;
using pll=pair<ll,ll>;
using bt=bitset<30>;
const ll N=2e5+5,K=30;
ll a[N],b[N],sum[K],cnt[K];
mt19937 rnd;

struct  node{
    node *lc,*rc;
    ll sum,idx,cnt;
    node (): lc(NULL), rc(NULL),sum(0),idx(0),cnt(0){}
    node (ll idx): lc(NULL), rc(NULL),sum(0),idx(idx),cnt(0){}
};
node *r[K];

void up(node* &nn,ll k,ll idx){
    if (idx>30) return;
    if (nn==NULL){
        nn=new node(idx);
    }
    nn->sum+=k>>idx;
    nn->cnt++;
    if (k&1<<(nn->idx+1)){
        up(nn->rc,k,idx+1);
    }
    else{
        up(nn->lc,k,idx+1);
    }
}

ll qu (node *nn,ll k,ll idx,ll ai,ll nt){
    if (nn==NULL) return 0;
    if (nn->idx == idx){
        ll nv=0,nc=0,re;
        if (nn->lc) nv+=nn->lc->sum,nc+=nn->lc->cnt;
        if (nn->rc) nv+=nn->rc->sum,nc+=nn->rc->cnt;
        re=(nv+ai*nc)*2ll+nc*nt;
        // cout << " => " << bt(k) << ' ' << bt(ai) << ' ' << bt(nv) << ' ' << idx << ' ' << nc << ' ' << nv << ' ' << nt << '\n';
        return re;
    }
    if (k&1<<(nn->idx+1)) return qu(nn->rc,k,idx,ai,nt);
    else return qu(nn->lc,k,idx,ai,nt);
}

bool test (int mode=0){
    ll n,ans=0,so=0,se=0;
    if (mode) n=rnd()%10;
    else cin >> n;
    ll tmp=0;
    for (ll i=1;i<=n;i++){
        if (mode) a[i]=1+(rnd())%(int(1e3-1));
        else cin >> a[i];
        // cout << bt(a[i]) << '\n';
        while (!(a[i]&1)){
            b[i]++;
            a[i]>>=1;
        }
        for (ll j=0;j<b[i];j++) ans+=(1<<(b[i]-j))*a[i]*cnt[j]+sum[j];
        for (ll j=b[i]+1;j<K;j++) ans+=(1<<(j-b[i]))*sum[j]+a[i]*cnt[j];
        for (ll j=1;j<K;j++){
            ll nk=(1<<j)-(a[i]%(1<<(j+1))),nt=1;
            if (nk<0) nk+=1<<(j+1),nt+=2;
            // cout << bt(a[i]%(1<<j+1)) << ' ' << bt(1<<j) << " = " << bt(nk) << ' ' << nk << '\n';
            ans+=qu(r[b[i]],nk,j,a[i]>>(j+1),nt);
        }
        // cout << " ? " << a[i] << ' ' << b[i] << '\n';
        ans+=a[i];
        // cout << " 1 " << i << " = " << ans-tmp << '\n';
        tmp=ans;
        sum[b[i]]+=a[i];
        cnt[b[i]]++;
        up(r[b[i]],a[i],0);
    }
    
    cout << ans;
    return 1;
    ll ans2=0;
    tmp=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            ll ns=(1<<b[i])*a[i]+(1<<b[j])*a[j];
            while (!(ns&1)){
                ns>>=1;
            }
            ans2+=ns;
        }
        // cout << " 2 " << i << " = " << ans2-tmp << '\n';
        tmp=ans2;
    }
    if (ans!=ans2){
        cout << n << '\n';
        for (int i=1;i<=n;i++) cout << (1<<b[i])*a[i] << ' ';
        cout << '\n' << ans << ' ' << ans2 << '\n';
    }
    for (int i=0;i<=n;i++){
        a[i]=b[i]=0;
    }
    for (int i=0;i<K;i++){
        sum[i]=cnt[i]=0;
        r[i]=new node();
    }
    // cout << ' ' << ans2;
    return ans==ans2;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    // int t=1000000;
    // while (t--){
    //     if (!test(1)) break;
    // }
    // cout << "ok\n";
    test(0);
}

/*

3
6096115 7412533 9364683
*/