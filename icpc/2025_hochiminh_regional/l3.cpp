#include <bits/stdc++.h>
using namespace std;

int ask(int mark){
    cout << mark << '\n'; cout.flush();
    char c; cin >> c;
    return c=='Y';
}

void solve(){
    int ask1 = 0;
    int ans = 1;
    int prev = false;
    int is_mark = false;
    while (1) {
        is_mark = ask(ask1 == 0);
        if (is_mark) {
            if (ask1==0) {
                is_mark = ask(0);
                prev = is_mark;
                // if (is_mark) {
                //     cout << "-1 1\n";
                //     cout.flush();
                //     return;
                // }
            }
            else {
                ask(0);
                prev = ask(1);
            }
            break;
        }
        ask1 = 1 - ask1;
    }
    int inp = false;
    // while (1) {
    //     ans++;
    //     inp = ask(0);
    //     if (inp&&prev) break;
    //     prev = inp;
    // }
    cout << "-1 " << ans << "\n";
    cout.flush();
    // exit(0);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}