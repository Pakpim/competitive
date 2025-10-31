#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ti=tuple<ll,ll,ll>;
const int N=2e5+5;
ll ar[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int l,r;
        cin >> l >> r;
        if (r!=1) cout << r-l << '\n';
        else cout << "1\n";
    }
}