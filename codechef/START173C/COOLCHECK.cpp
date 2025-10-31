#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=2e5+5;
int a[N],b[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,m;
        cin >> n >> m;
        for (int i=0;i<n;i++) cin >> a[i];
        for (int i=0;i<m;i++) cin >> b[i];
        sort(a,a+n);
        sort(b,b+n);
    }
}