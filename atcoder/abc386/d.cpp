#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    bool ok=1;
    map<int,int> b;
    vector<pair<int,int>> w;
    while (m--){
        int x,y;
        char c;
        cin >> x >> y >> c;
        if (c=='B'){
            b[x]=max(b[x],y);
        }
        else{
            w.emplace_back(x,y);
        }
    }
    sort(w.begin(),w.end());
    int mx=0;
    for (auto it=b.end();it!=b.begin();){
        it--;
        mx=max(mx,it->second);
        it->second=mx;
        // cout << " ==> " << it->first << ' ' << it->second << '\n';
    }
    auto it2=b.begin();
    for (int i=0;i<w.size();i++){
        while (it2!=b.end() && it2->first<w[i].first) it2++;
        // cout << " => " << it2->first << ' ' << it2->second << ' ' << w[i].second << '\n';
        if (it2!=b.end() && it2->second >= w[i].second) ok=0;
    }
    if (ok) cout << "Yes\n";
    else cout << "No\n";
}