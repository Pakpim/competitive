#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        string s;
        cin >> n >> s;
        char c='0';
        int cnt=0;
        for (auto e:s){
            if (e!=c){
                c=e;
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}