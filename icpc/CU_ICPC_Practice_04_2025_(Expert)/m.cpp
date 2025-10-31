#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=1e5+5;
bool f[N];
vector<ll> p;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i=2;i<N;i++){
        if (f[i]) continue;
        p.emplace_back(i);
        for (int j=i*2;j<N;j+=i) f[j]=1;
    }
    int t;
    cin >> t;
    while (t--){
        ll n,nn;
        cin >> n;
        nn=n;
        ll mn=n-1,a=1,b=n-1;
        for (auto e:p){
            if (nn%e==0 && nn/e*(e-1)<mn){
                mn=nn/e*(e-1);
                a=nn/e;
                b=nn/e*(e-1);
            }
            while (n%e==0) n/=e;
        }
        if (n!=1 && nn/n*(n-1)<mn){
            a=nn/n;
            b=nn/n*(n-1);
        }
        cout << a << ' ' << b << '\n';
    }
}