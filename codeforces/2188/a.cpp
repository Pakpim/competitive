#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=1e5+5;


signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int m=n/2 + (n&1);
        for (int i=1;i<=n;i++){
            cout << m << ' ';
            if (i&1) m+=i;
            else m-=i;
        }
        cout << '\n';
    }
}