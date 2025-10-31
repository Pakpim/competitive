#include <bits/stdc++.h>
using namespace std;

using ll=long long;

const ll N=200005;
ll w[N];
ll n,s,ans=1;

bool cal (ll x){
    ll sum=0;
    ll c1=0;
    ll c2=0;
    for (int i=1;i<=x;i++){
        
    }
    return false;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> s;
    for (int i=1;i<=n;i++) {
        cin >> w[i];
    }
    s--;
    sort(w+1,w+1+n);
    ll l=1,r=n-1;
    while (l<=r){
        ll mid=(l+r)/2;
        if (cal(mid)) l=mid+1,ans=min(ans,mid);
        else r=mid-1;
    }
    cout << ans+1;
}

/*
6 8
4 4 5 5 10 10
*/