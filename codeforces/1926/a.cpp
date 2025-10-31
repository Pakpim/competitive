#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        string s;
        int cnt[100];
        memset(cnt,0,sizeof cnt);
        cin >> s;
        for (auto e:s) cnt[e]++;
        if (cnt['A'] > cnt['B']) cout << "A\n";
        else cout << "B\n";
    }
}