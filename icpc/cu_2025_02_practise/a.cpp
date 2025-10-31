#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,k;
        cin >> n >> k;
        if (n<=k){
            cout << k/n + bool(k%n) << '\n';
        }
        else{
            if (n%k) cout << "2\n";
            else cout << "1\n";
        }
    }
}