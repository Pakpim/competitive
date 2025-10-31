#include <bits/stdc++.h>
using namespace std;

map<string,int>s,c;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    while (n--){
        string a,b;
        int p;
        cin >> a >> b >> p;
        s[a]+=p;
        s[b]+=p;
        c[a]++;
        c[b]++;
    }
    cout << fixed << setprecision(2);
    for (auto [k,v]:s) cout << k << ' ' << (v+0.0)/c[k] << '\n';
}