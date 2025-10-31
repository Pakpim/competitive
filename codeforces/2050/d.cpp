#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using db=double;
const ll N=2e5+5;

void solve(){
    string s;
    cin >> s;
    for (int i=0;i<s.size();i++){
        int j=i;
        while (j>0 && s[j]>'0' && s[j-1]<s[j]-1){
            s[j]--;
            swap(s[j],s[j-1]);
            j--;
        }
    }
    cout << s << '\n';
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}