#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    char a[]={'a','e','i','o','u'};
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i=0;i<5;i++){
            for (int j=0;j<n/5;j++){
                cout << a[i];
            }
            if (n%5>i) cout << a[i];
        }
        cout << '\n';
    }
}