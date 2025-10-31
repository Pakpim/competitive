#include <bits/stdc++.h>
using namespace std;

multiset<int> s;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    while (n--){
        int p;
        cin >> p;
        s.emplace(p);
    }
    for (int i=1;i<=m;i++){
        int k;
        bool ok=1;
        cin >> k;
        while (k--){
            int p;
            cin >> p;
            if (s.upper_bound(p)==s.end()){
                ok=0;
                break;
            }
            else s.erase(s.upper_bound(p));
        }
        if (!ok){
            cout << i;
            return 0;
        }
    }
    cout << m+1;
}