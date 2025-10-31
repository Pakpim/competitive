#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1005;;
vector <pair<int,int>> v[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll n,q,cnt=0;
        cin >> n >> q;
        while (q--){
            int x,l,r;
            cin >> x >> l >> r;
            v[x].emplace_back(l,r);
        }
        for (int i=1;i<=n;i++){
            if (v[i].empty()) continue;
            sort(v[i].begin(),v[i].end());
            int r=-1;
            bool ok=1;
            for (int k=0;k<v[i].size();k++){
                if (v[i][k].first<=r) ok=0;
                r=max(r,v[i][k].second);
            }
            if (ok) continue;
            bool f=0;
            for (int j=0;j<v[i].size();j++){
                int r=-1;
                bool ok=1;
                for (int k=0;k<v[i].size();k++){
                    if (j==k) continue;
                    if (v[i][k].first<=r) ok=0;
                    r=max(r,v[i][k].second);
                }
                if (ok) f=1;
            }
            if (f) cnt++;
            else cnt=1e9;
            v[i].clear();
        }
        if(cnt<2) cout << "YES\n";
        else cout << "NO\n";
    }
}