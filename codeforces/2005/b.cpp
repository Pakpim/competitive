#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,m,q;
        cin >> n >> m >> q;
        vector<int> v(m);
        for (auto &e:v) cin >> e;
        sort(v.begin(),v.end());
        while (q--){
            int p;
            cin >> p;
            auto it=lower_bound(v.begin(),v.end(),p);
            if (it==v.end()){
                cout << n-(*prev(it)) << '\n';
            }
            else if (it==v.begin()){
                cout << *it-1 << '\n';
            }
            else{
                int mid=(*prev(it)+*it)/2;
                cout << max(*it-mid-1,mid-*prev(it)) << '\n';
            }
        }
    }
}