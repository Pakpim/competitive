#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=500005;
ll ar[N],mn[N],tmp[N],n;

pair<ll,ll> inv (ll a,ll b){
    if (a==0) return {0,1};
    ll r=b%a,q=b/a;
    pair<ll,ll> p = inv(r,a);
    ll x=((p.second-q*p.first)%n+n)%n,y=p.first;
    return {x,y};
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll q,m=1,sum=0,k,j,p;
    cin >> n >> q;
    k=n; p=1; j=0;
    for (ll i=0;i<n;i++) ar[i]=i;
    ar[0]=n;
    while (q--){
        char c;
        ll x;
        cin >> c >> x;
        if (c=='?'){
            if (x%p!=j) cout << "-1\n";
            else {
                ll xp = (x/p);
                xp = (( (((xp-sum)%k+k)%k) *inv(m,k).first)%k+k)%k;
                cout << ar[xp] << '\n';
            }
        }
        if (c=='+') {
            j+=x;
            sum+=j/p; j%=p; sum%=k;
        } 
        if (c=='*'){
            if (__gcd(x,k)!=1){
                ll gcd=__gcd(x,k),tj,tk=k/gcd,tp=n/tk;
                for (ll i=0;i<k;i++){
                    mn[i]=1e9;
                    ll ip = (( (((i-sum)%k+k)%k) *inv(m,k).first)%k+k)%k;
                    tmp[i]=ar[ip];
                }
                for (ll i=0;i<k;i++) ar[i]=tmp[i];
                for (ll i=0;i<k;i++){
                    ll ip=(i*x*p+j*x)%n;
                    ll d=(((ip-(i*p+j))%n)+n)%n;
                    tj=ip%tp;
                    ip/=tp;
                    if (mn[ip]>d){
                        mn[ip]=d;
                        tmp[ip]=ar[i];
                    }
                }
                k=tk;
                p=tp;
                j=tj;
                for (ll i=0;i<k;i++) ar[i]=tmp[i];
                m=1;
                sum=0;
            }
            else{
                j*=x;
                sum*=x;
                sum+=j/p; j%=p; sum%=k;
                m*=x; m%=k;
            }
        }
    }
}