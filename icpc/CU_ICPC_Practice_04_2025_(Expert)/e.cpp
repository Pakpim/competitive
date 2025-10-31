#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=2e5+5;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll n,a,b;
        cin >> n >> a >> b;
        if (b<a) cout << "1\n";
        else{
            cout << n/a+bool(n%a) << '\n';
        }
    }
}