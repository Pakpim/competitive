#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=100005;
ll cnt[65];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll n,mx=1;
        cin >> n;
        for (int i=0;i<64;i++) cnt[i]=0;
        for (int i=0;i<n;i++){
            ll v,p=0;
            cin >> v;
            if (!v) continue;
            while (p<64 && 1ll<<p <= v) p++;
            p--;
            cnt[p]++;
        }
        for (int i=0;i<64;i++) mx=max(mx,cnt[i]);
        cout << mx << '\n';
    }
}