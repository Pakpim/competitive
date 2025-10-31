#include <iostream>
#include <vector>
#include <map>
using namespace std;

void insert_into_sv(map<int, int> &v, int pos, int value){
    // your code here
    vector<pair<int,int>> t;
    while (!v.empty() && v.rbegin()->first >= pos){
        t.emplace_back(v.rbegin()->first+1,v.rbegin()->second);
        v.erase(prev(v.end()));
    }
    v.insert(v.end(),make_pair(pos,value));
    for (int i=t.size()-1;i>=0;i--) v.insert(v.end(),t[i]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    map<int, int> v;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        insert_into_sv(v, a, b);
    }
    cout << v.size() << "\n";
    for (auto &x : v){
        cout << x.first << ": " << x.second << "\n";
    }
}
