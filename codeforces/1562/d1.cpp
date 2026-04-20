#include <bits/stdc++.h>
using namespace std;

const int N=3e5+5;
int a[N];

void solve(){
    int n,q,x=1;
    string s;
    cin >> n >> q >> s;
    for (int i=1;i<=n;i++) a[i]=a[i-1]+(s[i-1]=='+'? 1:-1)*x, x*=-1;
    while (q--){
        int l,r;
        cin >> l >> r;
        int sz=r-l+1;
        if (a[r]-a[l-1]==0) cout << "0\n";
        else if (sz&1) cout << "1\n";
        else cout << "2\n";
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}