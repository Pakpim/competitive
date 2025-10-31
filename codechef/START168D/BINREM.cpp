#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll n,x,k,cnt=0,inv=0;
        string s;
        cin >> n >> x >> k >> s;
        for (ll i=0;i<n;i++){
            if (s[i]=='1') cnt++;
            else inv+=cnt;
        }
        if (inv<=x && inv%k==0) cout << "1\n";
        else cout << "2\n";
    }
}