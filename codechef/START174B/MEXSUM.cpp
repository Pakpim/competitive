#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=2e5+5;
ll a[N],qs[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll n,mn=1e18,mx=-1;
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> a[i];
            qs[i]=qs[i-1]+a[i];
        }
        for (int i=2;i<=n;i++){

        }
    }
}