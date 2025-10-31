#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll b,c,d,a=0;
        bool ok=1;
        cin >> b >> c >> d;
        c=~c;
        a=b^d;
        if ((d&a)^(c&a)) ok=0;
        if (ok) cout << a << '\n';
        else cout << "-1\n";
    }
}