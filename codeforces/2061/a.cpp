#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,c0=0,c1=0;
        cin >> n;
        while (n--){
            int v;
            cin >> v;
            if (v&1) c1++;
            else c0++;
        }
        if (c0) cout << 1+c1 << '\n';
        else cout << c1-1 << '\n';
    }
}