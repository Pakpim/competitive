#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=1e5+5;


signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        string s;
        cin >> n >> s;
        int cnt=0, sum=0;
        for (auto e:s){
            if (e=='1'){
                cnt--;
                if (cnt>0){
                    sum+=cnt/3 + bool(cnt%3);
                    // cout << " =>" << cnt << ' ' << sum << '\n';
                }
                cnt=-1;
                sum++;
            }
            else{
                cnt++;
            }
        }
        if (cnt>0) sum+=cnt/3 + bool(cnt%3);
        // cout << " =>" << cnt << ' ' << sum << '\n';
        cout << sum << '\n';
    }
}