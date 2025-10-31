#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int m;
    cin >> m;
    vector<int> ans;
    for (int i=0;i<=10;i++){
        while (m%3){
            ans.emplace_back(i);
            m--;
        }
        m/=3;
    }
    cout << ans.size() << '\n';
    for (auto e:ans) cout << e << ' ';
}