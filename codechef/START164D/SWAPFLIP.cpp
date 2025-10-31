#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        string s,t;
        cin >> n >> s >> t;
        int cs=0,ct=0;
        for (auto e:s) if (e=='0')cs++;
        for (auto e:t) if (e=='0')ct++;
        if  (cs%2!=ct%2) cout << "NO\n";
        else cout << "YES\n";
    }
}