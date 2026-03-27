#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n[2];
    cin >> n[0] >> n[1];
    vector<tuple<int,string>> v[2];
    vector<tuple<int,int,string>> ans;
    set<string> s;
    for (int i=0;i<2;i++){
        for (int j=0,k=0;j<n[i];j++){
            string a;
            cin >> a;
            if (s.count(a)) continue;
            k++;
            s.emplace(a);
            v[i].emplace_back(k,a);
        }
        s.clear();
        for (auto [a,b]:v[i]) ans.emplace_back(a,i,b);
    }
    sort(ans.begin(),ans.end());
    for (auto [a,b,c]:ans){
        if (s.count(c)) continue;
        s.emplace(c);
        cout << c << '\n';
    }
}