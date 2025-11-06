#include <bits/stdc++.h>
using namespace std;

using lll=__int128_t;
using ll=long long;
const lll N=1e4+5;
lll n,c,a[N],b[N];

lll cal (lll x){
    lll re=0;
    for (int i=0;i<n;i++){
        re+=1 + (a[i]*x)/b[i];
    }
    return re;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int tn,tc;
    cin >> tn >> tc;
    n=tn; c=tc;
    lll cnt=0;
    for (int i=0;i<n;i++) {
        int ta,tb;
        cin >> ta >> tb;
        a[i]=ta; b[i]=tb;
        if (ta==0) cnt++;
    }
    if (cnt==n){
        if (c==n) cout << -1;
        else cout << 0;
        return 0;
    }
    lll l=1, r=1e18+5, lb=r, ub=r, mid;
    while (l<=r){
        mid = l+(r-l)/2;
        lll nv=cal(mid);
        if (nv>=c){
            lb=min(lb,mid);
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    l=1, r=1e18+5;
    while (l<=r){
        mid = l+(r-l)/2;
        lll nv=cal(mid);
        if (nv>c){
            ub=min(ub,mid);
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    // if (n==100 && c==100){
    //     cout << ll(ub) << ' ' << ll(lb) << '\n';
    //     cout << ll(cal(ub)) << ' ' << ll(cal(ub-1)) << '\n';
    //     cout << ll(cal(lb)) << ' ' << ll(cal(lb-1)) << '\n';
    // }
    // assert(cal(lb-1)<c);
    // assert(cal(lb)>=c);
    // assert(cal(ub-1)<=c);
    // assert(cal(ub)>c);
    // lll cnt=0;
    // for (lll i=0;i<=ub+5;i++){
    //     if (cal(i)==c) cnt++;
    // }
    ll ans=ub-lb;
    // assert(cnt==ans);
    cout << ans;
}