#include <iostream>
// #include "bits/stdc++.h"
#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,m;
        string a,b;
        bool ok=1;
        cin >> n >> m >> a >> b;
        for (int i=1;i<n;i++){
            if (a[i-1]==a[i]) ok=0;
        }
        if (ok){
            cout << "Yes\n";
            continue;
        }
        ok=1;
        for (int i=1;i<m;i++){
            if (b[i-1]==b[i]) ok=0;
        }
        if (b[0]!=b[m-1]) ok=0;
        for (int i=1;i<n;i++){
            if (a[i-1]==a[i] && a[i]==b[0]) ok=0;
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
}