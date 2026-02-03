#include <bits/stdc++.h>
using namespace std;

int a[1005][15];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) for (int j=0;j<m;j++) cin >> a[i][j];
    for (int i=1;i<=n;i++){
        bool f=0;
        for (int j=1;j<=n;j++){
            bool ok=1;
            for (int k=0;k<m;k++) ok&=a[i][k]<a[j][k];
            if (ok){
                cout << j << '\n';
                f=1;
                break;
            }
        }
        if (!f) cout << "0\n";
    }
}