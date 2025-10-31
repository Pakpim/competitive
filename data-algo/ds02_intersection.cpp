#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b;
    cin >> a >> b;
    vector<int> v1(a),v2(b);
    for (auto &e:v1) cin >> e;
    for (auto &e:v2) cin >> e;
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    v2.emplace_back(INT_MAX);
    int p=0,bf=INT_MAX;
    for (auto e:v1){
        if (bf==e) continue;
        bf=e;
        while (v2[p]<e) p++;
        if (v2[p]==e) cout << e << ' ';
    }
}