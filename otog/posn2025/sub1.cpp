#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ti=tuple<ll,int,int>;
using bt=bitset<10>;
const int N=1e5;
ll a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> a[i];
    k--;
    ll sum=0;
    for (int i=0;i<n;i++) if (k>>i&1) sum+=a[i];
    cout << sum;
}