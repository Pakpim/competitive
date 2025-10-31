#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=2e5+5;
int a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,cnt=0;
        bool ok=1;
        cin >> n;
        for (int i=2;i<n;i++){
            cin >> a[i];
            if (i>2 && a[i] && !a[i-1] && a[i-2]) ok=0;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}