#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5,M=1e9+7;
ll f[6*N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll n,k;
        cin >> n >> k;
        n%=M;
        if (k==1){
            cout << n << '\n';
            continue;
        }
        f[0]=0; f[1]=1;
        ll i;
        for (i=2;;i++){
            f[i]=(f[i-1]+f[i-2])%k;
            if (f[i]==0) break;
        }
        cout << (i*n)%M << '\n';
    }
}