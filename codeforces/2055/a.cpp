#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,a,b;
        cin >> n >> a >> b;
        if (a>b) swap(a,b);
        if ((a-b)&1) cout << "NO\n";
        else cout << "YES\n";
    }
}