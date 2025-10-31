#include <bits/stdc++.h>

using namespace std;

set<int> s;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    while (n--){
        int x;
        cin >> x;
        s.emplace(x);
    }
    while (m--){
        int x;
        cin >> x;
        auto it = s.lower_bound(x);
        int a=*it;
        if (it==s.begin()){
            cout << *it << ' ';
            continue;
        }
        it--;
        int b=*it;
        if (a-x <= x-b) cout << a << '\n';
        
    }
}