#include <bits/stdc++.h>
using namespace std;

int qu=0;

int interact(int mark){
    qu++;
    cout << mark << '\n'; fflush(stdout);
    char c; cin >> c;
    return c=='Y';
}

void solve(){
    int c=0;
    while (1){
        int re = interact(c%2);
        if (re){
            if (c!=re){
                interact(0);
            }
            break;
        }
        c = 1-c;
    }
    int p=1, cnt=1;
    while (1){
        int re = interact(1);
        if (p == re) break;
        p = re;
        cnt ++;
    }
    cout << "-1 " << cnt << '\n';
    cout << " = " << qu << '\n';
    fflush(stdout);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}