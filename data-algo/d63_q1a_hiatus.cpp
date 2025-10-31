#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<pair<int,int>> v(n);
    for (auto &[y,m]:v) cin >> y >> m;
    v.emplace_back(1e9,1e9);
    sort(v.begin(),v.end());
    while (q--){
        int y,m;
        cin >> y >> m;
        auto it=lower_bound(v.begin(),v.end(),make_pair(y,m));
        if (it->first==y && it->second==m) cout << "0 0 ";
        else if (it==v.begin()) cout << "-1 -1 ";
        else{ 
            it--;
            cout << it->first << ' ' << it->second << ' ';
        }
    }
}