#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using db=double;
const ll N=2e5+5;

void solve(){
    int n,m;
    cin >> n >> m;
    int ans=n;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        if (s.size()>m) ans=min(ans,i-1);
        else m-=s.size();
    }
    cout << ans << '\n';
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}