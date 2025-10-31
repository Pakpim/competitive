#include <bits/stdc++.h>
using namespace std;

set<int> s;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    while (m--){
        int l,sz;
        cin >> l >> sz;
        if (s.find(l)==s.end()) s.emplace(l);
        else s.erase(l); 
        if (s.find(l+sz)==s.end()) s.emplace(l+sz);
        else s.erase(l+sz);
    }
    s.emplace(1);
    s.emplace(n+1);
    while (q--){
        int x;
        cin >> x;
        auto it =s.upper_bound(x);
        auto it2 = it;
        it2--;
        cout << (*it)-(*it2) << '\n';
    }
}