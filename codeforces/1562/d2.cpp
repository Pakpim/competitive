#include <bits/stdc++.h>
using namespace std;

const int N=3e5+5;
int a[N],b[N];
vector<int> v[N*2];

void solve(){
    int n,q,x=1;
    string s;
    cin >> n >> q >> s;
    for (int i=-n;i<=n;i++) v[i+n].clear();
    for (int i=1;i<=n;i++) a[i]=a[i-1]+(s[i-1]=='+'? 1:-1)*x, x*=-1;
    for (int i=1;i<=n;i++) {
        b[i]=a[i-1]-(a[n]-a[i]);
        // cout << i << " = " << b[i] << '\n';
        v[b[i]+n].emplace_back(i);
    }
    while (q--){
        int l,r;
        cin >> l >> r;
        int sz=r-l+1;
        if (a[r]-a[l-1]==0) {
            cout << "0\n";
            continue;
        }
        if (sz&1) cout << "1\n";
        else {
            cout << "2\n" << r << ' ';
            r--;
        }
        int nv=(-a[l-1]+(a[n]-a[r]))*-1;
        auto it=lower_bound(v[nv+n].begin(),v[nv+n].end(),l);
        int tg=*it;
        cout << tg << '\n';
        // cout << " ? " << nv << ' ' << a[tg-1]-a[l-1]-(a[n]-a[tg])+(a[n]-a[r]) << '\n';
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