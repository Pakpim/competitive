#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int m,n;
    cin >> n >> m;
    vector<int> a(n),b(n),mx(m,1);
    multiset<int> s(mx.begin(),mx.end());
    for (auto &e:b) cin >> e;
    for (auto &e:a) cin >> e;
    for (int i=0;i<n;i++){
        auto it=s.find(mx[a[i]]);
        s.erase(it);
        mx[a[i]]=max(mx[a[i]],b[i]);
        s.emplace(mx[a[i]]);
        cout << *s.begin() << ' ';
    }
}