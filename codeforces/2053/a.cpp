#include <bits/stdc++.h>
using namespace std;

const int N=205;
int a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        bool f=0;
        cin >> n;
        for (int i=0;i<n;i++){
            cin >> a[i];
            if (i && ((a[i]>=a[i-1] && a[i]<a[i-1]*2) ||(a[i]<a[i-1] && a[i-1]<a[i]*2))) f=1;
        }
        if (f) cout << "Yes\n";
        else cout << "No\n";
    }
}