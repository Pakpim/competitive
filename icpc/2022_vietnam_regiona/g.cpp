#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,r,x1,x2;
    cin >> n >> r >> x1 >> x2;
    vector<int> v(n);
    for (auto &e:v) cin >> e;
    bool f=0;
    if (x1>x2){
        for (auto e:v){
            f|=(e>=x1+r);
        }
    }
    else{
        for (auto e:v){
            f|=(e<=x1-r);
        }
    }
    if (f) cout << "GOAL";
    else cout << "NO GOAL";
}