#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=200005;
ll a[N],mx=0,x=0;
set<ll> v;
vector<ll> tmp;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,k;
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<k;i++){
        v.emplace(i);
        x^=a[i];
    }
    tmp.emplace_back(k-1);

    cout << mx;
}