#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,k;
        cin >> n >> k;
        k--;
        if (n&1) n--;
        cout << n/k+bool(n%k) << '\n';
    }
}