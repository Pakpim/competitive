#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,mx=0;
        cin >> n;
        for (int i=1;i<=n;i++){
            int a;
            cin >> a;
            if (a>mx) cout << "1 ";
            else cout << "0 ";
            mx=max(mx,a);
        }
        cout << '\n';
    }
}