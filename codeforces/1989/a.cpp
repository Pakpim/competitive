#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    while (n--){
        int x,y;
        cin >> x >> y;
        if (y<-1) cout << "NO\n";
        else cout << "YES\n";
    }
}