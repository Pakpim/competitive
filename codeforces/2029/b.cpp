#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        string a,b;
        vector<int> cnt(2,0);
        bool ok=1;
        cin >> n >> a >> b;
        for (auto e:a) cnt[e-'0']++;
        for (auto e:b){
            if (cnt[0]==0 || cnt[1]==0){
                ok=0;
                break;
            }
            if (e=='0') cnt[1]--;
            else cnt[0]--;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}