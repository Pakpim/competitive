#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using db=double;
const ll N=2e5+5;

bool solve(){
    int n;
    cin >> n;
    ll s[]={0,0},c[]={0,0};
    for (int i=0;i<n;i++){
        ll v;
        cin >> v;
        s[i&1]+=v;
        c[i&1]++;
    }
    if (s[0]%c[0]==0 && s[1]%c[1]==0 && s[0]/c[0]==s[1]/c[1]) return true;
    return false;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }
}