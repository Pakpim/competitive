#include <bits/stdc++.h>
using namespace std;
bool ask(int n) {
    cout << n << '\n';
    cout.flush();
    char inp;
    cin >> inp;
    return (inp == 'Y');
}
void solve() {
    int ask1=0;
    int ans = 1;
    bool prev = false;
    bool is_mark = false;
    while (true) {
        if (ask1 == 0) is_mark = ask(1);
        else is_mark = ask(0);
        if (is_mark) {
            if (ask1==0) {
                is_mark = ask(0);
                prev = is_mark;
                if (is_mark) {
                    cout << "-1 1\n";
                    cout.flush();
                    return;
                }
            }
            else {
                ask(0);
                prev = ask(1);
            }
            break;
        }
        ask1 = (ask1+1)%2;
    }
    bool inp = false;
    while (true) {
        ans++;
        inp = ask(0);
        if (inp&&prev) break;
        prev = inp;
    }
    cout << "-1 " << ans << "\n";
    cout.flush();
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
}