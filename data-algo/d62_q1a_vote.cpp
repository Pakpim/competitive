#include <bits/stdc++.h>
using namespace std;

map<string,int> m;
vector<int> v;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;
    while (n--){
        string s;
        cin >> s;
        m[s]++;
    }
    for (auto [a,b]:m)v.emplace_back(b);
    sort(v.begin(),v.end());
    cout << *(max(v.end()-k,v.begin()));
}