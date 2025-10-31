#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll n,x,y;
        cin >> n >> x >> y;
        for (int i=1;i<y;i++) {
            if ((i&1)==((y-1)&1)) cout << "-1 ";
            else cout << "1 ";
        }
        for (int i=y;i<=x;i++) cout << "1 ";
        for (int i=x+1;i<=n;i++) {
            if ((i&1)==((x+1)&1)) cout << "-1 ";
            else cout << "1 ";
        }
        cout << '\n';
    }
}