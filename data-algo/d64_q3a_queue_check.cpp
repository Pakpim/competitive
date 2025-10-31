#include <bits/stdc++.h>
using namespace std;

void ans (){
    int f,s,c,l,o;
    cin >> f >> s >> c >> l >> o;
    if (c >= s && c > f && c >l && (f+s)%c==l) {
        cout << "OK";
        return;
    }
    cout << "WRONG ";
    if (o == 1) cout << (l+c-s)%c;
    if (o == 2) cout << (l-f+c)%c;
    if (o == 3) {
        int tmp;
        tmp=max({f+1,s,l+1});
        if (l<f){
            // f+s-c = l
            tmp=f+s-l;
        }
        cout << tmp;
    }
    if (o == 4) cout << (f+s)%c;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ans();
        cout << '\n';
    }
}

/*
10
0 0 1 0 0
0 2 4 2 0
0 8 8 20 0
0 2 4 0 0
0 2 4 0 2
0 2 4 0 4
1 3 8 7 1
10 100 8 110 3
3 8 2 3 3
3 2 0 5 3
*/