#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,l,r;
        cin >> n >> l >> r;
        vector<ll> v(n);
        for (auto &e:v) cin >> e;
        sort(v.begin(),v.end());
        bool zero=0;
        for (int i=1;i<n;i++){
            if (v[i]==v[i-1]) zero=1;
        }
        if (zero){
            if (l<=0) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        if (n>34){
            cout << "NO\n";
            continue;
        } 
        ll sum=1;
        for (int i=0;i<n;i++){
            for (int j=0;j<i;j++){
                sum*=v[i]^v[j];
            }
        }
        if (sum>=l && sum<=r) cout << "YES\n";
        else cout << "NO\n";
    }
}