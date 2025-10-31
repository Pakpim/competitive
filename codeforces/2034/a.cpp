#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int a,b;
        cin >> a >> b;
        cout << a*b/__gcd(a,b) << '\n';
    }
}