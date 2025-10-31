#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll M=1e9+7;

ll bp (ll a,ll b){
    ll re=1;
    while (b){
        if (b&1) re=(re*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return re;
}

ll cal (ll l,ll r){
    return ((l+r)*(r-l+1)/2)%M;
}

ll cal2(ll l,ll r){
    l--;
    return ((r*(r+1)*(2*r+1))/6 - (l*(l+1)*(2*l+1))/6)%M;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll n,k,sum=0;
        cin >> n >> k;
        ll sq=sqrt(n);
        for (ll i=2;i<=min(k,sq);i++){
            ll nv=n,cnt=0;
            while (nv){
                cnt++;
                cnt%=M;
                nv/=i;
            }
            nv=n;
            while (nv){
                cnt--;
                sum+=((nv%i)*bp(i,cnt))%M;
                sum%=M;
                nv/=i;
            }
        }
        for (ll i=n/sq;i>=1;i--){
            ll nk=min(k,n/(i+1))+1,xk=min(n+1,k+1);
            if (nk <= sq) continue;
            if (i>1) xk=min(xk,n/i+1);
            sum+=i*(xk-nk)%M+(n*cal(nk,xk-1))%M-(i*cal2(nk,xk-1))%M;
            sum=((sum%M)+M)%M;
            if (nk>k) break;
        }
        if (k>n){
            sum+=(n*((k-n)%M))%M;
            sum%=M;
        }
        cout << sum << '\n';
    }
}