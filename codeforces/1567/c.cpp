#include <bits/stdc++.h>
using namespace std;

using ll=long long;
ll dp[15][2];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i=0;i<=14;i++) dp[i][0]=dp[i][1]=0;
        dp[0][0]=1;
        for (int i=1;n;i++, n/=10){
            for (int j=0;j<=9;j++){
                for (int k=j+1;j<9;j++){
                    dp[i][0]=
                }
            }
        }
    }
}