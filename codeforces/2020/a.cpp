#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,k,cnt=0;
        cin >> n >> k;
        if (k==1){
            cout << n << '\n';
            continue;
        }
        while (n){
            if (n%k) cnt+=n%k;
            n/=k;
        }
        cout << cnt << '\n';
    }
}