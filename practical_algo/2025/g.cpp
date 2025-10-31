#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5,K=8e6+5;
ll a[N],n,m;

ll cal (int c){
    ll re=0;
    ll l=1,r=K,mid;
    while (l<=r){
        mid=l+(r-l)/2;
        ll sum=0,cnt=0;
        for (int i=0;i<n;i++){
            int na=a[i]/mid, nb=a[i]%mid;
            int nu=na+bool(nb);
            sum+=(a[i]/nu+1)*(a[i]/nu+1)*(a[i]%nu)+(a[i]/nu)*(a[i]/nu)*(nu-a[i]%nu);
            cnt+=nu;
        }
        if (cnt>c) r=mid-1;
        else{
            l=mid+1;
            
            re=max(re,sum);
        }
    }
    return re;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    ll l=0,r=m,mid;
    while (l<=r){
        mid=l+(r-l)/2;
        ll nv=cal(mid);

    }
}