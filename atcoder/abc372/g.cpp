#include <bits/stdc++.h>
using namespace std;

const int N=200005;
int a[N],b[N],c[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,sum=0;
        cin >> n;
        for (int i=0;i<n;i++) cin >> a[i] >> b[i] >> c[i];
        
        cout << sum << '\n';
    }
}