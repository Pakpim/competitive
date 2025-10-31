#include <bits/stdc++.h>
using namespace std;

set<pair<string,string>> s;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    while (n--){
        string a,b;
        cin >> a >> b;
        s.emplace(a,b);
    }
    while (m--){
        int k;
        cin >> k;
        vector<pair<string,string>> v;
        bool ok=1;
        while (k--){
            string a,b;
            cin >> a >> b;
            v.emplace_back(a,b);
            if (!s.count({a,b})) ok=0;
        }
        if (ok) {
            cout << "YES\n";
            for (auto e:v) s.erase(e);
        }
        else cout << "NO\n";
    }
}