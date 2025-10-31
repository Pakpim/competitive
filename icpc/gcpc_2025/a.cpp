#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll l, r;
    cin >> l >> r;
    if (l == r) {
        // if (l!=2) exit(1);
        cout << 3ll * l;
    }
    else if (l == r + 2ll) {
        // exit(1);
        cout << r + 2ll * l - 1ll;
    }
    else if (l == r + 1ll) cout << 2ll * l - 1ll;
    else cout << (l + r) * 2ll;
}