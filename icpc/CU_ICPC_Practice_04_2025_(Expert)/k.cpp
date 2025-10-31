#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,sum=0,mn=1e18;
    cin >> n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            ll a;
            cin >> a;
            sum+=a;
            if (i+j==n-1) mn=min(mn,a);
        }
    }
    cout << sum-mn;
}