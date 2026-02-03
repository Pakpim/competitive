#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5;
ll dp[50][3][3];

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll x,y;
        cin >> x >> y;
        ll st;
        bool f=0;
        for (st=30;st>=0;st--){
            if ((x>>st&1) == 1 &&  (y>>st&1)== 1){
                f=1;
                break;
            }
        }
        if (!f){
            cout << x << ' ' << y << '\n';
            continue;
        }
        for (int i=0;i<=32;i++) for (int j=0;j<3;j++) for (int k=0;k<3;k++) dp[i][j][k]=1e9;
        for (int i=30;i>=0;i--){
            if ((x>>i&1) == 1  &&  (y>>i&1)== 1){
                dp[i][]
            }
        }
    }
}