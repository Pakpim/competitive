#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5;
string db[3]={"R","L","LR"};
vector<int> pos[3];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    int q;
    cin >> s >> q;
    int st=0;
    for (int i=0;i<s.size();i++){
        if (s[i]=='R'){
            if (!st) pos[0].emplace_back(i);
            else{
                st=0;
                pos[0].emplace_back(i);
                pos[1].emplace_back(i-1);
                pos[2].emplace_back(i-1);
            }
        }
        else{
            if (!st) st=1;
            else pos[1].emplace_back(i-1);
        }
    }
    if (st) pos[1].emplace_back(s.size()-1);
    // for (int t=0;t<3;t++){
    //     cout << db[t] << " : ";
    //     for (auto e:pos[t]) cout << e << ' ';
    //     cout << '\n';
    // }
    while (q--){
        string t;
        cin >> t;
        vector<int> v;
        st=0;
        for (auto e:t){
            if (e=='R'){
                if (!st) v.emplace_back(0);
                else st=0, v.emplace_back(2);
            }
            else{
                if (!st) st=1;
                else v.emplace_back(1);
            }
        }
        if (st) v.emplace_back(1);
        int np=0;
        bool ok=1;
        for (auto e:v){
            // cout  << " ? " << db[e] << ' ' << np << '\n';
            auto it = lower_bound(pos[e].begin(), pos[e].end(), np);
            if (it==pos[e].end()){
                ok=0;
                break;
            }
            np=*it;
            np++;
            if (e==2) np++;
        }
        if (v[0]==0 && (pos[0].empty() || pos[0][0]!=0)) ok=0;
        if (v.back()==1 && (pos[1].empty() || pos[1].back()!=s.size()-1)) ok=0; 
        cout << (ok? "YES":"NO") << '\n';
    }
}