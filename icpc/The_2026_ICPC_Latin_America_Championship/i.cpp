#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int c[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        c[a]++;
    }
    int odd=0;
    for (int i=1;i<=n;i++){
        if (c[i]&1) odd++;
    }
    if (n&1){
        if (odd>1) cout << "S";
        else cout << "E";
    }
    else{
        if (!odd) cout << "E";
        else cout << "F";
    }
}