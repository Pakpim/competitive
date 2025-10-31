#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    vector<int> v;
    while (q--){
        string s;
        cin >> s;
        if (s=="pb"){
            int x;
            cin >> x;
            v.emplace_back(x);
        }
        if (s=="sa"){
            sort(v.begin(),v.end());
        }
        if (s=="sd"){
            sort(v.begin(),v.end(),greater<int>());
        }
        if (s=="r"){
            reverse(v.begin(),v.end());
        }
        if (s=="d"){
            int i;
            cin >> i;
            v.erase(v.begin()+i);
        }
    }
    for (auto e:v) cout << e << ' ';
}