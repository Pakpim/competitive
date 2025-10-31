#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5;
ll a[N],qs[N],n;
set<ll> vis;
map<ll,ll> mx;
mt19937 rnd;

ll solve(){
    ll ans=0;
    vis.clear();
    mx.clear();
    for (ll i=1;i<=n;i++){
        ll nv=0;
        qs[i]=qs[i-1]^a[i];
        if (mx.count(a[i]^qs[i-1])){
            nv=a[i]+mx[a[i]^qs[i-1]];
            mx.erase(a[i]^qs[i-1]);
        }
        else{
            nv=a[i];
        }
        mx[a[i]^qs[i]]=nv;
        // cout << a[i] << " ? " << qs[i] << ' ' << (qs[i]^a[i]) << ' ' << (qs[i-1]^a[i]) << ' ' << nv << '\n';
        ans=max(ans,nv);
    }
    return ans;
}

ll solve2(){
    ll re=0;
    for (ll i=0;i<2048;i++){
        ll sum=0,nv=i;
        for (ll j=1;j<=n;j++){
            if (nv==a[j]) sum+=a[j];
            else nv^=a[j];
        }
        re=max(re,sum);
    }
    return re;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    bool test=0;
    t=1000;
    if (!test) cin >> t;
    while (t--){
        n=rnd()%10000+1;
        if (!test) cin >> n;
        for (ll i=1;i<=n;i++){
            a[i]=rnd()%1024;
            if (!test) cin >> a[i];
        }
        if (test){
            ll a1=solve(),a2=solve2();
            if (a1!=a2){
                cout << n << '\n';
                for (ll i=1;i<=n;i++) cout << a[i] << ' ';
                cout << '\n' << a1 << " , " << a2;
                break;
            }
        }
        else cout << solve() << '\n';
    }
}

/*
10
10 4 20 19 7 19 5 3 9 28 
48 , 47

1
5
19 19 18 11 25 
44 , 43
*/