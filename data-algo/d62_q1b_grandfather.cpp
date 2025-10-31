#include <bits/stdc++.h>
using namespace std;

using ll=long long;
map<ll,ll> par;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    ll a,b;
    cin >> n >> m;
    while (n--){
        cin >> a >> b;
        par[b]=a;
    }
    while (m--){
        cin >> a >> b;
        if (par.find(a)==par.end() || par.find(b)==par.end() || a==b) {
            cout << "NO\n";
            continue;
        }
        a=par[a]; b=par[b];
        if (par.find(a)==par.end() || par.find(b)==par.end() || par[a]!=par[b]) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}