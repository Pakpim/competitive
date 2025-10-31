#include <iostream>
using namespace std;

using ll=long long;
const ll N=1e6+5,M=998244353;
ll f[N],inf[N];

ll bp (ll a,ll b){
    ll re=1;
    while (b){
        if (b&1) re=(a*re)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return re;
}

ll com (ll n,ll r){
    return (((f[n]*inf[r])%M) * inf[n-r])%M;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    f[0]=1;
    for (ll i=1;i<N;i++) f[i]=(f[i-1]*i)%M;
    inf[N-1]=bp(f[N-1],M-2);
    for (ll i=N-2;i>=0;i--) inf[i]=(inf[i+1]*(i+1))%M;
    ll t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        for (int i=1;i<=(n-1)/2;i++){
            ll sum=1;
            for (int j=2*i;j+1<=n;j+=2*i) {
                sum+=((com(n,j)-com(n-(j-2*(i-1)-1),i*2-1))%M) +M;
                sum%=M;
            }
            cout << sum << ' ';
        }
        cout << '\n';
    }
}