#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        set<int> s;
        int n,ans=-1;
        bool f=0;
        cin >> n;
        while (n--){
            int a;
            cin >> a;
            if (s.count(a)){
                f=1;
                ans=a;
            }
            s.emplace(a);
        }
        if (f) cout << 1 << '\n' << ans << '\n';
        else cout << "-1\n";
    }
}