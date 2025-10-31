#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N=1e6+5;
bool f[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    f[1]=1;
    for (int i=2;i<N;i++){
        if(f[i]) continue;
        for (int j=i*2;j<N;j+=i) f[j]=1;
    }
    ll n;
    cin >> n;
    while (n--){
        ll v;
        cin >> v;
        ll sq=sqrt(v);
        if (sq*sq==v && !f[sq]) cout << "YES\n";
        else cout << "NO\n";
    }
    
}