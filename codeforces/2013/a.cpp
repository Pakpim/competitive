#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,x,y;
        cin >> n >> x >> y;
        x=min(x,y);
        cout << n/x+(n%x!=0) << '\n';
    }
}