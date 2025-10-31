#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ti=tuple<ll,int,int>;
const int N=1e5;
ll a[N];
vector<ll> v;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<1<<n;i++){
        ll sum=0;
        for (int j=0;j<n;j++){
            if (i>>j&1) sum+=a[j];
        }
        v.emplace_back(sum);
    }
    sort(v.begin(),v.end());
    cout << v[k-1];
}